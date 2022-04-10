#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> good(0);
	vector<int> bad(0);
	for (int i = 0; i < n; i++) {
		int g;
		cin >> g;
		if (g >= 93) {
			good.push_back(g);
		} else {
			bad.push_back(g);
		}
	}
	sort(good.begin(), good.end());
	sort(bad.begin(), bad.end());
	// butchered bad
	int badInd = 0;
	for (int i = 0; i < (int)bad.size() - (int)good.size() * k && badInd < bad.size(); i++, badInd++) {
		cout << (i == 0 ? "" : " ") << bad[badInd];
	}
	// rest
	for (int i = 0; i < good.size(); i++) {
		cout << (badInd == 0 && i == 0 ? "" : " ") << good[i];
		for (int j = 0; j < k && badInd < bad.size(); j++, badInd++) {
			cout << " " << bad[badInd];
		}
	}

	return 0;
}
