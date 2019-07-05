/* Result: (DFS, not DP) TLE 70 */
#include <iostream>
#include <cmath>

using namespace std;

int ok[20][20] = {{0}};
int okCnt[20] = {0};
int n, arr[20], k;
int f[16][16][65536] = {{0}};

long long total = 0;

/* // Brute-force: 70 points
void dfs(int depth, int used, int last) {
	if (depth == n) {
		++ total;
		return;
	}
	used |= 1 << last;
	for (int i = 0; i < okCnt[last]; ++ i) {
		if (!(used & (1 << ok[last][i]))) {
			dfs(depth + 1, used, ok[last][i]);
		}
	}
}
*/

int main() {
	
	cin >> n >> k;
	
	for (int i = 0; i < n; ++ i) cin >> arr[i];
	for (int i = 0; i < n; ++ i)
		for (int j = i + 1; j < n; ++ j) {
			int delta = abs(arr[i] - arr[j]);
			if (delta > k) {
				ok[i][okCnt[i] ++] = j;
				ok[j][okCnt[j] ++] = i;
			}
		}
	
	for (int i = 0; i < n; ++ i) {
		// dfs(1, 0, i);
		f[i][1][1 << i] = 1;
	}
	
	for (int depth = 1; depth <= n; ++ depth)
	for (int last = 0; last < n; ++ last) {
		for (int j = 0; j < 65536; ++ j) {
			for (int i = 1; i < okCnt[last]; ++ i) {
				if (f[last][depth][j] != 0 && !(j & (1 << ok[last][i]))) {
					f[ok[last][i]][depth + 1][j|(1<<ok[last][i])] += f[last][depth][j];
					cout << f[ok[last][i]][depth + 1][j|(1<<ok[last][i])] << endl;
				}
			}
		}
	}
	
	cout << total;
	
	return 0;
	
}