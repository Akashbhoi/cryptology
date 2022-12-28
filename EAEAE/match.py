import re
cipher = open("cipher.txt", "r")
plain = open("plaintext.txt", "r")
str1 = input()
pattern = "^" + str1
needPattern = re.compile(pattern)


count = 1
lineNo = -1
for line in cipher:
    if needPattern.match(line):
        lineNo = count
        break
    else:
        count = count + 1

count = 1
output = ""
for line in plain:
    if count == lineNo:
        output = line
        break
    else:
        count = count + 1

print( str1, " = ", output[0:len(str1)])
next = output[0:len(str1)]

while len(next) < 16:
    next = next + "f"

print("The next s is :", next)