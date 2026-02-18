import sys
input = sys.stdin.readline

expr = input().strip()
parts = expr.split('-')
result = 0

for i in range(len(parts)):
    nums = parts[i].split('+')
    total = sum(map(int, nums))

    if(i == 0):
        result += total
    else :
        result -= total

print(result)
