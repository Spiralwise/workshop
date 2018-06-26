#!/usr/bin/python3
# -*- coding:utf-8 -*-

# See https://www.reddit.com/r/dailyprogrammer/comments/4lpygb/20160530_challenge_269_easy_basic_formatting/
import sys

# Definition
INDENT = "    "

# Variables
output = ""
level = 0

# Main
N = int(sys.stdin.getline()) # Unused value, I admit.
for line in sys.stdin.getlines():
    trimmed_line = line.strip(' \t.»')
    for i in range(level):
        output += INDENT
    output += trimmed_line
    if trimmed_line.startswith('IF') or trimmed_line.startswith('FOR'):
        level += 1
    elif trimmed_line.startswith('ENDIF') or trimmed_line.startswith('NEXT'):
        level -= 1

print(output)
