le = int(input())
masses = list(map(int, input().split()))
masses.sort()
min_ = -1
for i in range(2**(le-1), 2**le):
    h1, h2 = 0, 0
    mask = str(bin(i))[2:]
    while len(mask) < le:
        mask = "0" + mask
    c = 0
    for l in mask:
        if l == "0":
            h1 += masses[c]
        else:
            h2 += masses[c]
        c += 1
    if min_ == -1:
        min_ = abs(h1-h2)
    else:
        min_ = min(min_, abs(h1-h2))
    
print(min_)