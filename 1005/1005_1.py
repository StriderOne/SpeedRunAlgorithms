input()
stones = list(map(int,input().split()))
min_ = 10000000
for i in range(2**(len(stones)-1)):
    s = bin(i)[2:]
    mask =  "0"*(len(stones) -len(s)) + s
    sum1, sum2 = 0, 0
    for j in range(len(stones)):
        if mask[j] == "0":
            sum1 += stones[j]
        else:
            sum2 += stones[j]
    min_ = min(min_, abs(sum1-sum2))
print(min_)