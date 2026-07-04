#!/usr/bin/env python3

import base64
import json
import pathlib
import subprocess
import sys
import tempfile


def main() -> int:
    if len(sys.argv) != 2:
        print("Usage: submission.py <source_file>")
        return 1

    source_file = pathlib.Path(sys.argv[1])
    if not source_file.exists():
        print(f"File not found: {source_file}")
        return 1

    problem_code = source_file.stem
    ext = source_file.suffix.lower()
    if ext == ".cpp":
        language_substring = "GNU G++23"
    elif ext == ".rs":
        language_substring = "Rust 1.89.0 (2024)"
    else:
        return 1

    source_code = source_file.read_text()

    js = f"""
(() => {{
  const problemCode = {json.dumps(problem_code)};
  const languageSubstring = {json.dumps(language_substring)};
  const sourceCode = {json.dumps(source_code)};

  function waiting(msg) {{
    return "waiting: " + msg;
  }}

  function failed(msg) {{
    return "failed: " + msg;
  }}

  function setValue(el, value) {{
    el.value = value;
    el.dispatchEvent(new Event("input", {{ bubbles: true }}));
    el.dispatchEvent(new Event("change", {{ bubbles: true }}));
  }}

  function setSourceCode(value) {{
    const aceEditorElement = document.querySelector("#editor.ace_editor");
    if (window.ace && aceEditorElement) {{
      const editor = window.ace.edit(aceEditorElement);
      editor.setValue(value, -1);
      editor.clearSelection();
      editor.session.getUndoManager().reset();
    }}

    const sourceTextarea = document.querySelector('textarea[name="source"]');
    if (!sourceTextarea) return false;

    setValue(sourceTextarea, value);
    return true;
  }}

  function getSourceCode() {{
    const aceEditorElement = document.querySelector("#editor.ace_editor");
    if (window.ace && aceEditorElement) {{
      return window.ace.edit(aceEditorElement).getValue();
    }}

    const sourceTextarea = document.querySelector('textarea[name="source"]');
    return sourceTextarea ? sourceTextarea.value : null;
  }}

  if (!/^https?:\\/\\/(?:www\\.)?codeforces\\.com\\/problemset\\/submit(?:[/?#]|$)/.test(location.href)) {{
    return waiting("submit page to open; currently at " + location.href);
  }}

  if (document.readyState === "loading") {{
    return waiting("document to finish loading");
  }}

  const problemInput = document.querySelector('input[name="submittedProblemCode"]');
  if (!problemInput) return waiting("problem code input");

  const languageSelect = document.querySelector('select[name="programTypeId"]');
  if (!languageSelect) return waiting("language selector");

  const option = Array.from(languageSelect.options).find(
    opt => opt.textContent.includes(languageSubstring)
  );

  if (!option) {{
    const available = Array.from(languageSelect.options)
      .map(opt => opt.textContent.trim())
      .filter(Boolean)
      .join("\\n");

    if (available) {{
      return failed("Language not found: " + languageSubstring + "\\nAvailable:\\n" + available);
    }}

    return waiting("language options");
  }}

  const sourceTextarea = document.querySelector('textarea[name="source"]');
  const aceEditorElement = document.querySelector("#editor.ace_editor");
  if (!sourceTextarea && !(window.ace && aceEditorElement)) return waiting("source editor");

  setValue(problemInput, problemCode);
  languageSelect.value = option.value;
  languageSelect.dispatchEvent(new Event("input", {{ bubbles: true }}));
  languageSelect.dispatchEvent(new Event("change", {{ bubbles: true }}));
  if (!setSourceCode(sourceCode)) return waiting("source editor to accept value");

  if (problemInput.value !== problemCode) {{
    return waiting("problem code input to accept value");
  }}

  if (languageSelect.value !== option.value) {{
    return waiting("language selector to accept value");
  }}

  if (getSourceCode() !== sourceCode) {{
    return waiting("source editor to accept value");
  }}

  return "filled";
}})();
"""

    encoded_js = base64.b64encode(js.encode()).decode()
    jxa_payload_lines = [
        "const jsPayload = [",
        *(
            f"  {json.dumps(encoded_js[i:i + 12000])},"
            for i in range(0, len(encoded_js), 12000)
        ),
        "].join('');",
    ]
    jxa_payload = "\n".join(jxa_payload_lines)

    jxa = f"""
const app = Application.currentApplication();
app.includeStandardAdditions = true;

const Safari = Application("Safari");
Safari.activate();

function findSubmitTab() {{
  const submitUrl = /^https?:\\/\\/(?:www\\.)?codeforces\\.com\\/problemset\\/submit(?:[/?#]|$)/;

  for (const window of Safari.windows()) {{
    for (const tab of window.tabs()) {{
      const url = tab.url();
      if (url && submitUrl.test(url)) {{
        return tab;
      }}
    }}
  }}

  return null;
}}

if (!findSubmitTab()) {{
  app.openLocation("https://codeforces.com/problemset/submit");
}}

const timeoutMs = 30000;
const startedAt = Date.now();
let lastStatus = "waiting: Safari to open the submit page";

{jxa_payload}
const scriptSource = "eval(atob('" + jsPayload + "'))";

delay(0.2);

while (true) {{
  try {{
    const targetTab = findSubmitTab();
    if (!targetTab) {{
      lastStatus = "waiting: submit page tab";
    }} else {{
      lastStatus = Safari.doJavaScript(scriptSource, {{ in: targetTab }});
    }}
  }} catch (error) {{
    lastStatus = "waiting: " + error.message;
  }}

  if (lastStatus === "filled") {{
    break;
  }}

  if (lastStatus.startsWith("failed: ")) {{
    throw new Error("[cf_submit_safari] " + lastStatus);
  }}

  if (Date.now() - startedAt > timeoutMs) {{
    throw new Error(
      "[cf_submit_safari] Timed out after " +
        timeoutMs / 1000 +
        " seconds; last status: " +
        lastStatus
    );
  }}

  delay(0.25);
}}
"""

    with tempfile.NamedTemporaryFile("w", suffix=".jxa.js", delete=False) as f:
        f.write(jxa)
        script_path = f.name

    try:
        subprocess.run(["/usr/bin/osascript", "-l", "JavaScript", script_path], check=True)
    except Exception:
        print(f"Generated script kept for debugging: {script_path}", file=sys.stderr)
        raise
    else:
        pathlib.Path(script_path).unlink(missing_ok=True)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
