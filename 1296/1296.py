max_ = 0
s = 0
n = int(input())
for i in range(n):
    a = int(input())
    if s + a <= 0:
        s = 0
    else:
        s += a
        max_ = max(max_, s)
print(max_)