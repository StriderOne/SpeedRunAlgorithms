for _ in range(int(input())):
    n, k = tuple(map(int, input().split()))
    per_team = n//k
    teams = []
    for i in range(n % k):
        teams.append(per_team + 1)
    while len(teams) < k:
        teams.append(per_team)
    s = 0
    used = 0
    for elem in teams:
        s += elem * (n - used - elem)
        used += elem
    print(s)