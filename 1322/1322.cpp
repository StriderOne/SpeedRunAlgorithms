#include <iostream>
#include <algorithm>
using namespace std;

bool compare(const pair<int, char>& x1, const pair<int, char>& x2){
    return x1.second < x2.second;
}
// Преобразование Барроуза — Уилера
int main() {
    int n;
    string s;
    string ans = "";
    cin >> n >> s;
    n--;

    pair<int, char> inv[s.size()];
    for (int i = 0; i < s.size(); i++){
        inv[i].first = i;
        inv[i].second = s[i];
    }
    stable_sort(inv, inv + s.size(), compare);

    for (int i = 0; i < s.size(); i++) {
        n = inv[n].first;
        // cout << n << endl;
        ans += s[n];
    }
    cout << ans << endl;
    return 0;
}