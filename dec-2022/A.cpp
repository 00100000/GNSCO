#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        sum += temp;
    }
    cout << sum / n;
    return 0;
}
