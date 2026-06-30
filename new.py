#!/usr/bin/env python3

import argparse
import re
import sys
from pathlib import Path
import subprocess

import requests
from bs4 import BeautifulSoup


def open_in_vscode(file: Path) -> None:
    if subprocess.run(["which", "code"], capture_output=True).returncode == 0:
        subprocess.run(["code", str(file)], check=False)
    else:
        subprocess.run(["open", str(file)], check=False)


def problem_to_url(problem: str) -> str:
    if problem.startswith(("http://", "https://")):
        return problem

    m = re.fullmatch(r"(\d+)([A-Za-z][A-Za-z0-9]*)", problem)
    if not m:
        raise ValueError("Problem must look like 2050C or be a Codeforces URL.")

    return f"https://codeforces.com/problemset/problem/{m.group(1)}/{m.group(2)}"


def problem_slug(problem: str) -> str:
    if not problem.startswith(("http://", "https://")):
        return re.sub(r"[^A-Za-z0-9_.-]+", "_", problem)

    parts = Path(problem).parts
    for i in range(len(parts) - 1):
        if parts[i] in ("problemset", "contest", "gym") and i + 2 < len(parts):
            return re.sub(r"[^A-Za-z0-9_.-]+", "_", parts[i + 1] + parts[i + 2])

    return re.sub(r"[^A-Za-z0-9_.-]+", "_", problem)


def pre_to_text(pre) -> str:
    for br in pre.find_all("br"):
        br.replace_with("\n")
    text = pre.get_text()
    return text.replace("\xa0", " ").strip("\n") + "\n"


def create_cpp_file(template: Path, cpp_file: Path, problem: str, url: str, force: bool) -> None:
    text = template.read_text(encoding="utf-8") if template.exists() else "// Template not found\n"
    text = text.replace("{{PROBLEM}}", problem).replace("{{URL}}", url)

    if cpp_file.exists() and not force:
        print(f"{cpp_file} already exists; use --force to overwrite.")
        return

    cpp_file.write_text(text, encoding="utf-8")


def download_samples(url: str, slug: str, samples_dir: Path, force: bool) -> int:
    r = requests.get(url, timeout=20)
    r.raise_for_status()

    soup = BeautifulSoup(r.text, "html.parser")
    statement = soup.select_one(".problem-statement")
    if statement is None:
        print("Could not find problem statement; skipping samples.")
        return 0

    inputs = statement.select(".sample-test .input pre")
    outputs = statement.select(".sample-test .output pre")

    if len(inputs) != len(outputs):
        print("Sample count mismatch; skipping samples.")
        return 0

    samples_dir.mkdir(parents=True, exist_ok=True)
    written = 0

    for i, (inp, out) in enumerate(zip(inputs, outputs), start=1):
        in_file = samples_dir / f"{slug}.in{i}"
        out_file = samples_dir / f"{slug}.out{i}"

        if in_file.exists() and out_file.exists() and not force:
            print(f"Skipping existing sample {i}; use --force to overwrite.")
            continue

        in_file.write_text(pre_to_text(inp), encoding="utf-8")
        out_file.write_text(pre_to_text(out), encoding="utf-8")
        written += 1

    return written


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("problem", help="Example: 2050C or full Codeforces problem URL")
    parser.add_argument("-t", "--template", default="./Template/template.cpp", help="Path to C++ template")
    parser.add_argument("-s", "--samples", default="./samples", help="Samples directory")
    parser.add_argument("--force", action="store_true", help="Overwrite existing files")
    parser.add_argument("--open", action="store_true", help="Open the generated file")

    args = parser.parse_args()

    try:
        url = problem_to_url(args.problem)
        slug = problem_slug(args.problem)

        cpp_file = Path(f"{slug}.cpp")
        template = Path(args.template)
        samples_dir = Path(args.samples)

        create_cpp_file(template, cpp_file, slug, url, args.force)

        sample_count = download_samples(url, slug, samples_dir, args.force)

        print(f"Created: {cpp_file}")
        if sample_count:
            print(f"Downloaded {sample_count} sample(s) to: {samples_dir}/")
        print(f"URL: {url}")

        if args.open:
            open_in_vscode(cpp_file)

        return 0

    except Exception as e:
        print(f"error: {e}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())