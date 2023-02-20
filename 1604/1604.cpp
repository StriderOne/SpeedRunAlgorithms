#include <iostream>
using namespace std;

struct Counter {
	int amount;
	int index;
};

pair<int, int> findMinMax(Counter* array, int k) {
	static pair<int, int> currentPair = make_pair(0, 0);
	int minAmount = INT_MAX, maxAmount = INT_MIN;
	for(int i = 0; i < k; i++) {
		if (array[i].amount > 0) {
			if (array[i].amount >= maxAmount) {
				maxAmount = array[i].amount;
				currentPair.second = i;
			}
			if (array[i].amount < minAmount) {
				minAmount = array[i].amount;
				currentPair.first = i;
			}
		}
	}
	return currentPair;
}

int main() {
	int k, minAmount = INT_MAX, maxAmount = INT_MIN, amountOfcounters = 0;
	cin >> k;
	Counter counters[k];
	for (int i = 0; i < k; i++) {
		cin >> counters[i].amount;
		counters[i].index = i + 1;
		amountOfcounters += counters[i].amount;
	}
	pair<int, int> countersPair;
	while (amountOfcounters > 0) {
		countersPair = findMinMax(counters, k);
		if (counters[countersPair.second].amount > 0) {
			cout << counters[countersPair.second].index << " ";
			counters[countersPair.second].amount--;
			amountOfcounters--;
		}
		if (counters[countersPair.first].amount > 0) {
			cout << counters[countersPair.first].index << " ";
			counters[countersPair.first].amount--;
			amountOfcounters--;
		}
	}
	return 0;
}
