max_ = 0
s = 0
for _ in range(int(input())):
    a = int(input())
    if s + a > 0:
        s += a
        max_ = max(max_, s)
    else:
        s = 0
print(max_)