#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.compare("good") == 0) cnt++;
	}

	cout << cnt;
	return 0;
}
