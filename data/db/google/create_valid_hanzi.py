import create_db_from_google
hanzi = create_db_from_google.get_validate_hanzi()
hanzi = list(hanzi)
hanzi.sort()
print "# -*- coding: utf-8 -*- "
print "valid_hanzi = set(["
for c in hanzi:
    print "    u\"%s\"," % c.encode("utf8")
print "])"
