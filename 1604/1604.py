n = int(input())
ans = ""
s = list(map(int, input().split()))
keys = [str(i) for i in range(1, n+1)]

# sdict = {str(i+1):s[i] for i in range(n)}

while len(s) > 1:
    keys = [x for _, x in sorted(zip(s,keys))]
    s.sort()
    ans += keys[-1] + " " + keys[0] + " "
    if s[-1] == 1:
        s.remove(s[-1])
        keys.remove(keys[-1])
    else:
        s[-1] -= 1
    
    if s[0] == 1:
        s.remove(s[0])
        keys.remove(keys[0])
    else:
        s[0] -= 1
    # print(keys, s, ans)
    
# print(keys, s, ans)
if len(keys) > 0:
    ans += keys[0]

print(ans)