#!/usr/bin/env bash
# Converts man_1_simple_shell.md to troff (man format) using pandoc
# The --standalone option is necessary; without it, Pandoc will naïvely translate the Markdown to troff without
# providing the header, footer, or the general man page structure to the output.
pandoc --standalone -f markdown -t man man_1_simple_shell.md > man_1_simple_shell

