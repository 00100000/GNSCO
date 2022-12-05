#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, x;
	cin >> a >> b >> x;

	cout << b - a + min(a, x - b) + 1;
	return 0;
}
