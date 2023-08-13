#!/usr/bin/env python3

import re


FILES_TO_PARSE = [
    {"filepath": "docs/api/cpp/doomGame.md", "namespace": "DoomGamePython"},
    {"filepath": "docs/api/cpp/utils.md"},
]
OUTPUT_FILE = "src/lib_python/ViZDoomMethodsDocstrings.h"
RAW_STRING_ESCAPE_SEQ = "DOCSTRING"
FUNCTION_HEADER_REGEX = r"^##+ *`([a-zA-Z]+)` *$"
TO_REPLACE = [
    (r"\[([`a-zA-Z]+)\]\(.*\)", r"\1"),  # Links
    ("true", "True"),  # cpp -> python bool
    ("false", "False"),  # cpp -> python bool
]
LINES_TO_IGNORE_REGEXES = [
    r"---",  # Lines
    r"^\|.+\|$",  # Tables
    r"^See also:.*$",  # See also
    r"- \[.*\]\(.*\)",  # List of links starting with -
    r"\* \[.*\]\(.*\)",  # List of links starting with *
    r"^Added in .*$",  # Added in annotations
    r"^Changed in .*$",  # Changed in annotations
    r"^Deprecated since .*$",  # Deprecated since annotations
    r"^Removed in .*$",  # Removed in annotations
    r"^Config key: .*$",  # Config annotations
    r"^Python aliases .*$",  # Python aliasses
    r"^#+.*",  # Other headings
]


if __name__ == "__main__":
    with open(OUTPUT_FILE, "w") as output_file:
        output_file.write(
            """/*
    This file is autogenerated by scripts/create_python_docstrings_from_cpp_docs.py
    Do not edit it manually. Edit the Markdown files under docs/api/cpp/ directory instead and regenerate it.
*/

#ifndef __VIZDOOM_METHODS_DOCSTRINGS_H__
#define __VIZDOOM_METHODS_DOCSTRINGS_H__

namespace vizdoom {
namespace docstrings {

"""
        )

        for file in FILES_TO_PARSE:
            if "namespace" in file:
                output_file.write(f"namespace {file['namespace']} {{\n\n")

            with open(file["filepath"]) as input_file:
                lines = input_file.readlines()

            started = False
            next_docstring = ""
            for line in lines:
                # If lines match pattern, extract the function name and arguments
                match = re.match(FUNCTION_HEADER_REGEX, line)
                if match:
                    if started:
                        next_docstring = next_docstring.strip()
                        next_docstring += f'){RAW_STRING_ESCAPE_SEQ}";\n\n'
                        output_file.write(next_docstring)

                    next_docstring = ""
                    function_name = match.group(1)
                    output_file.write(
                        f'    const char *{function_name} = R"{RAW_STRING_ESCAPE_SEQ}('
                    )
                    started = True

                elif started:
                    # Filter out some lines
                    if not any(re.match(r, line) for r in LINES_TO_IGNORE_REGEXES):
                        for r in TO_REPLACE:
                            line = re.sub(r[0], r[1], line)
                        next_docstring += line

            if started:
                output_file.write(
                    f'{next_docstring.strip()}){RAW_STRING_ESCAPE_SEQ}";\n\n'
                )

            if "namespace" in file:
                output_file.write(f"}} // namespace {file['namespace']}\n\n")

        output_file.write(
            """
} // namespace docstrings
} // namespace vizdoom

#endif
"""
        )
