#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int good = 0;
	int bad = 0;
	for (int i = 0; i < n; i++) {
		int g;
		cin >> g;
		if (g >= 93) {
			good++;
		} else {
			bad++;
		}
	}

	cout << max(0, bad - good * k);
	return 0;
}
