import re
import sys

orig_stdout = sys.stdout
f = open('output.txt', 'w')
sys.stdout = f

inp=""
with open("inp.txt","r") as file:
    inp=file.read()

mul_pattern = r"mul\((\d+),(\d+)\)"
do_pattern = r"do\(\)"
dont_pattern = r"don't\(\)"

instructions = re.split(r"(\bdo\(\)|\bdon't\(\)|mul\(\d+,\d+\))", inp)

enable = True
ans = 0

for instr in instructions:
    if re.match(do_pattern, instr):
        enable = True
    elif re.match(dont_pattern, instr):
        enable = False
    elif re.match(mul_pattern, instr):
        if enable:
            x, y = map(int, re.findall(r"\d+", instr))
            ans += x * y

print(ans)

sys.stdout = orig_stdout
f.close()


