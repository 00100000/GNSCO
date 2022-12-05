#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long b, n, m;
	cin >> b >> n >> m;
    b %= m;

	long long ans = 1;
    while (n > 0) {
		if (n & 1) ans = (ans * b) % m;
		n = n >> 1;
		b = (b * b) % m;
	}

	cout << ans;
	return 0;
}
