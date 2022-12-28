import re

pattern = re.compile(
    "Slowly, a new text starts appearing on the screen. It reads ...")
flagged = False
isFirst = True
f = open("cipher.txt", "w")

for line in open("out.txt"):
    if flagged:
        flagged = False
        if isFirst:
            isFirst = False
        else:
            f.write("{}\n".format(line.strip()))
    else:
        for match in re.finditer(pattern, line):
            if match:
                flagged = True

f.close()
