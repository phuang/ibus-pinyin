#!/usr/bin/env python
import sys

def add_header(name, header):
    with file(name) as fin:
        lines = fin.readlines()
    with file(name, "w") as fout:
        for l in header:
            print >> fout, l,
        if lines[0].startswith("/*") and lines[0].endswith("*/\n"):
            pass
        else:
            print >> fout, lines[0],
        for l in lines[1:]:
            print >> fout, l,

def main():
    with file("header") as f:
        header = f.readlines()
    for name in sys.argv[1:]:
        add_header(name, header)

if __name__ == "__main__":
    main()
