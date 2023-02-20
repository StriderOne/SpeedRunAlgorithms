l = 0
n = int(input())
x = []
y = []
for i in range(n):
    x_, y_ = map(int, input().split())
    x.append(x_)
    y.append(y_)
x.sort()
y.sort()
for i in range(1, n):
    l += (abs(x[i-1]-x[i]) + abs(y[i-1]-y[i])) * i * (n-i) * 2
print(int(l/(n*(n-1))))
