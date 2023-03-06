n = int(input())
people = dict()
people_loc = dict()
cities = dict()
counter = dict()
cities_arr = []

for i in range(n):
    name, city, money = input().split()

    people[name] = int(money)
    people_loc[name] = city

    if not city in cities_arr:
        cities[city] = 0
        counter[city] = 0
        cities_arr.append(city)
    cities[city] += int(money)


days, visits = map(int, input().split())
day = 1
visits_counter = 1
if visits != 0:
    visit_day, name, city = input().split()
    visit_day = int(visit_day)
else: 
    visit_day = -1


while day <= days:
    max_city = max(cities, key=cities.get)
    if list(cities.values()).count(cities[max_city]) == 1:
        counter[max_city] += 1
    if visit_day == day:
        while visit_day == day:
            cities[people_loc[name]] -= people[name]
            if not city in cities_arr:
                cities_arr.append(city)
                cities[city] = 0
                counter[city] = 0
            cities[city] += people[name]
            people_loc[name] = city
            if visits_counter >= visits:
                break
            visit_day, name, city = input().split()
            visit_day = int(visit_day)
            visits_counter += 1
    day += 1

for name in sorted(cities.keys()):
    if counter[name] != 0:
        print(name, counter[name])