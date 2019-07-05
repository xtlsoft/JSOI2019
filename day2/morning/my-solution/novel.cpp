#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, k;
map<int, int> mp[1002];
bool vis[1002];
int minn = 0x3f3f3f3f;

void dfs(int magic, int curr, int sum) {
	if (curr == n) {
		minn = min(minn, sum);
		return;
	}
	if (sum >= minn) return;
	if (vis[curr]) return;
	vis[curr] = true;
	for (map<int, int>::iterator it = mp[curr].begin(); it != mp[curr].end(); ++ it) {
		if (magic > 0) dfs(magic - 1, it->first, sum);
		dfs(magic, it->first, max(sum, it->second));
	}
	vis[curr] = false;
}

int main() {
	
	freopen("novel.in", "r", stdin);
	freopen("novel.out", "w", stdout);
	
	cin >> n >> m >> k;
	
	for (int i = 0; i < m; ++ i) {
		int _x, _y, _v;
		cin >> _x >> _y >> _v;
		mp[_x][_y] = _v;
		mp[_y][_x] = _v;
	}
	
	dfs(k, 1, 0);
	
	if (minn == 0x3f3f3f3f) cout << -1;
	else cout << minn;
	
	return 0;
	
}