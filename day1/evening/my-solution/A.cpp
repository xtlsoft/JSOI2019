/* Result: TLE 30 */
#include <iostream>
#define MOD_S 100000000

using namespace std;

typedef long long LL;

LL total = 1;
int m, n;

int can[14][14] = {{0}};

void dfs(int x, int y) {
	if (x != -1 && y != -1 && can[x][y]) {
		total = (total + 1) % MOD_S;
	}
	int org1 = can[x - 1][y], org2 = can[x][y - 1], org3 = can[x + 1][y], org4 = can[x][y + 1];
	can[x - 1][y] = can[x][y - 1] = can[x + 1][y] = can[x][y + 1] = 0;
	for (int newx = x; newx <= m; ++ newx)
		for (int newy = newx == x ? y + 1 : 1; newy <= n; ++ newy) {
			if (can[newx][newy]) {
				dfs(newx, newy);
			}
		}
	can[x - 1][y] = org1, can[x][y - 1] = org2, can[x + 1][y] = org3, can[x][y + 1] = org4;
}

int main() {
	
	cin >> m >> n;
	
	for (int i = 1; i <= m; i ++)
		for (int j = 1; j <= n; j ++) {
			int tmp; cin >> tmp;
			if (tmp) can[i][j] = 1;
			else can[i][j] = 0;
		}
	
	dfs(0, 0);
	
	cout << total;
	
}