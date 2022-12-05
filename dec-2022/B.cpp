#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    map<string, int> t1;
    map<string, int> t2;
    map<string, int> kills1;
    map<string, int> kills2;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        t1[temp] = 1;
    }
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        t2[temp] = 1;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string p1, p2;
        int team1, team2;
        cin >> p1 >> team1 >> p2 >> team2;
        if (team1 == 1) {
            t2[p2] = 0;
            kills1[p1]++;
        } else if (team1 == 2) {
            t1[p2] = 0;
            kills2[p1]++;
        }
    }
    for (auto& i : kills1) {
        if (i.second == n) {
            cout << "YES";
            return 0;
        }
    }
    for (auto& i : kills2) {
        if (i.second == n) {
            cout << "YES";
            return 0;
        }
    }
    
    cout << "NO";
    return 0;
}
