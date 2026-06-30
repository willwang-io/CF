#!/usr/bin/env python3

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

  function fail(msg) {{
    throw new Error("[cf_submit_safari] " + msg);
  }}

  function setValue(el, value) {{
    el.value = value;
    el.dispatchEvent(new Event("input", {{ bubbles: true }}));
    el.dispatchEvent(new Event("change", {{ bubbles: true }}));
  }}

  const problemInput = document.querySelector('input[name="submittedProblemCode"]');
  if (!problemInput) fail("Could not find problem code input.");
  setValue(problemInput, problemCode);

  const languageSelect = document.querySelector('select[name="programTypeId"]');
  if (!languageSelect) fail("Could not find language selector.");

  const option = Array.from(languageSelect.options).find(
    opt => opt.textContent.includes(languageSubstring)
  );

  if (!option) {{
    const available = Array.from(languageSelect.options)
      .map(opt => opt.textContent.trim())
      .filter(Boolean)
      .join("\\n");

    fail("Language not found: " + languageSubstring + "\\nAvailable:\\n" + available);
  }}

  languageSelect.value = option.value;
  languageSelect.dispatchEvent(new Event("change", {{ bubbles: true }}));

  const sourceTextarea = document.querySelector('textarea[name="source"]');
  if (!sourceTextarea) fail("Could not find source textarea.");
  setValue(sourceTextarea, sourceCode);

  "filled";
}})();
"""

    applescript = f"""
tell application "Safari"
    activate
    open location "https://codeforces.com/problemset/submit"
end tell

delay 2

tell application "Safari"
    set targetTab to current tab of front window
    do JavaScript {json.dumps(js)} in targetTab
end tell
"""

    with tempfile.NamedTemporaryFile("w", suffix=".applescript", delete=False) as f:
        f.write(applescript)
        script_path = f.name

    subprocess.run(["osascript", script_path], check=True)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())