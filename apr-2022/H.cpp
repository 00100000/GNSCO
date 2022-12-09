#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

int r, c, n, m;
vector<vector<char>> grid;
vector<vector<bool>> startpath;
vector<vector<bool>> endpath;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}
// Direction you're TRAVELLING when hitting a sign
// 1 = Top
// 2 = Right
// 3 = Left
// 4 = Down
int turn(int d, char sign) {
	if (sign == '/') {
		if (d == 1) return 2;
		if (d == 2) return 1;
		if (d == 3) return 4;
		if (d == 4) return 3;
	} else {
		if (d == 1) return 3;
		if (d == 2) return 4;
		if (d == 3) return 1;
		if (d == 4) return 2;
	}
	return 0;
}
 
void traverse(int x, int y, int direction, bool start) {
	if (x < 0 || y < 0 || x > r - 1 || y > c - 1) return;
	if (grid[x][y] != '.') direction = turn(direction, grid[x][y]);
	else if (start) startpath[x][y] = true;
	else endpath[x][y] = true;

	if (direction == 1) traverse(x - 1, y, 1, start);
	if (direction == 2) traverse(x, y + 1, 2, start);
	if (direction == 3) traverse(x, y - 1, 3, start);
	if (direction == 4) traverse(x + 1, y, 4, start);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> r >> c >> n >> m;
 
	grid.resize(r, vector<char>(c));
	startpath.resize(r, vector<bool>(c));
	endpath.resize(r, vector<bool>(c));
	for (int i = 0; i < r; i++) fill(grid[i].begin(), grid[i].end(), '.');
	for (int i = 0; i < n; i++) {
		int ri, ci;
		cin >> ri >> ci;
		ri--;
		ci--;
		grid[ri][ci] = '/';
	}
	for (int i = 0; i < m; i++) {
		int ri, ci;
		cin >> ri >> ci;
		ri--;
		ci--;
		grid[ri][ci] = '\\';
	}
	traverse(0, 0, 2, true);
	traverse(r - 1, c - 1, 3, false);
	// complete path
	if (endpath[0][0] || startpath[r - 1][c - 1]) {
		cout << "Moo";
		return 0;
	}
	vector<pair<int, int>> sol(0);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (startpath[i][j] && endpath[i][j]) {
				sol.push_back({i, j});
			}
		}
	}
	sort(sol.begin(), sol.end(), cmp);
	// no path
	if (sol.size() == 0) {
		cout << "Impossible";
		return 0;
	}
	// sol
	cout << sol.size() << "\n";
	for (int i = 0; i < (int)sol.size(); i++) {
		cout << sol[i].first + 1 << " " << sol[i].second + 1 << "\n";
	}
	return 0;
}
