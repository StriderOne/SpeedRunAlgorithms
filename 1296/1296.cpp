#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    long long a[601000];
    long long prefix[601000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0)
            prefix[i] = a[i];
        else
            prefix[i] += prefix[i - 1] + a[i];
    }

    // cout << endl;
    long long min_ = 0;
    long long max_ = -30000000000;
    for (int i = 0; i < n; i++) {
        max_ = max(max_, prefix[i] - min_);
        min_ = min(min_, prefix[i]);
        
    }
    cout << max(max_,0ll);
    return 0;
}
