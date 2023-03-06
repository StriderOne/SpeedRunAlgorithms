#include <iostream>
#include <string>
#include <map>
#include <ranges>
#include <set>
#include <algorithm>

int main()
{
    int n, money, days, visits, day, visit_counter, visit_day;
    std::string name, city;
    std::cin >> n;
    std::map<std::string, int> people;
    std::map<std::string, std::string> people_loc;
    std::map<std::string, int> cities;
    std::map<std::string, int> counter;
    std::set<std::string> cities_arr;

    std::cout << n << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << i << std::endl;
        std::cin >> name;
        std::cin >> city;
        std::cin >> money;
        std::cout << name << " " << city << " " << money << std::endl;
        people[name] = money;
        people_loc[name] = city;
        if (std::find(cities_arr.begin(), cities_arr.end(), city) == cities_arr.end())
            cities_arr.insert(city);
        cities[city] += money;
    }

    std::cin >> days >> visits;
    day = 1;
    visit_counter = 1;

    if (visits != 0)
        std::cin >> visit_day >> name >> city;
    else
        visit_day = -1;

    while (day <= days)
    {
        int new_max = 0;
        std::string new_key = "";
        for (std::map<std::string, int>::iterator it = cities.begin(); it != cities.end(); ++it)
        {
            if (it->second > new_max)
            {
                new_max = it->second;
                new_key = it->first;
            }
            else if (it->second == new_max)
            {
                new_key = "";
            }
        }
        if (new_key != "")
            counter[new_key] += 1;

        if (visit_day == day)
        {
            while (visit_day == day)
            {
                cities[people_loc[name]] -= people[name];
                if (std::find(cities_arr.begin(), cities_arr.end(), city) == cities_arr.end())
                {
                    cities_arr.insert(city);
                }
                cities[city] += people[name];
                people_loc[name] = city;
                if (visit_counter >= visits)
                    break;
                std::cin >> visit_day >> name >> city;
                visit_counter++;
            }
        }
    }
    for (std::string name : cities_arr)
    {
        if (counter[name] > 0)
            std::cout << name << counter[name] << std::endl;
    }
    return 0;
}