
def get_validate_hanzi():
    validate_hanzi = file("valid_utf16.txt").read().decode("utf16")
    return set(validate_hanzi)

def main():
    hanzi = get_validate_hanzi()
    hanzi = list(hanzi)
    hanzi.sort()
    print "# -*- coding: utf-8 -*- "
    print "valid_hanzi = set(["
    for c in hanzi:
        print "    u\"%s\"," % c.encode("utf8")
    print "])"

if __name__ == "__main__":
    main()
