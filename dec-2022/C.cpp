#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include <algo/debug.h>
#endif

typedef long long ll;
 
ll MOD = 1e9 + 7;
// sorts by attack/health
// a.a/a.h > b.a/b.h = a.a * b.h > b.a * a.h
bool cmp(pair<ll, ll>& a, pair<ll, ll>& b) { return a.first * b.second > b.first * a.second; }
 
ll floorMod(ll x) { return (x % MOD + MOD) % MOD; }
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, x;
	cin >> n >> x;
	vector<pair<ll, ll>> ah(n);
	for (int i = 0; i < n; i++) {
		int hi = 0;
		cin >> ah[i].first >> hi;
		ah[i].second = hi / x + (hi % x == 0 ? 0 : 1);
	}
	sort(ah.begin(), ah.end(), cmp);
 
	ll damage = 0;
	for (int i = 0; i < n; i++) {
		damage += ah[i].first;
		damage %= MOD;
	}
	ll ehealth = 1;
	for (int i = 0; i < n; i++) {
		ehealth += damage * ah[i].second;
		ehealth %= MOD;
		damage -= ah[i].first;
		damage = floorMod(damage);
	}
	
	cout << ehealth;
	return 0;
}
