#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <cstdio>

using namespace std;

map<int, vector<int> > mp[50002];
int n, m, k;
int minn = 0x3f3f3f3f;

void dfs(int depth, int curr, int sum) {
	if (depth == k) {
		minn = min(minn, sum);
		return;
	}
	if (sum >= minn) return;
	for (map<int, vector<int> >::iterator it = mp[curr].begin(); it != mp[curr].end(); ++ it) {
		for (vector<int>::iterator ite = it->second.begin(); ite != it->second.end(); ++ ite) {
			dfs(depth + 1, it->first, sum + *ite);
		}
	}
}

int main() {
	
	freopen("leaf.in", "r", stdin);
	freopen("leaf.out", "w", stdout);
	
	cin >> n >> m >> k;
	
	for (int i = 0; i < m; ++ i) {
		int _x, _y, _z, _c;
		cin >> _x >> _y >> _z >> _c;
		if (_c) continue;
		mp[_x][_y].push_back(_z);
	}
	
	dfs(0, 0, 0);
	
	cout << minn;
	
	return 0;
	
}