#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

int main() {
    long long n, a[10000];
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int last = pow(2, n) - 1;
    long long min1 = 100000000;
    for (int i = 0; i <= last; i++) {
        bitset<20> bitset2{i};
        long long sum1 = 0, sum2 = 0;
        
        for (int j = 0; j < n; j++) {
            if (bitset2[j] == 0) {
                sum1 += a[j];
            } else {
                sum2 += a[j];
            }

        }
        // cout << sum1 << " " << sum2 << endl;
        min1 = min(abs(sum1 - sum2), min1);
        
        // cout << bitset2 << endl;
    } 
    cout << min1;
    return 0;
}
