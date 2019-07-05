/* Result: WA 0 */
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

inline bool check2(int n) {
	return !(n % 2);
}

int main() {
	
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	
	int level = 1; // 0 or 1
	int dp[100001][3] = {{0}};
	int map[100001][3] = {{0}};
	int currStart[3] = {0, 1, 2};
	int n; cin >> n;
	for (int i = 0; i < n; ++ i) {
		cin >> map[i][0] >> map[i][1] >> map[i][2];
	}
	int maxn = 0;
	
	DO_SEARCH:
	memset(dp, 0, sizeof(dp));
	currStart[0] = 0; currStart[1] = 1; currStart[2] = 2;
	dp[0][0] = map[0][0], dp[0][1] = map[0][1], dp[0][2] = map[0][2];
	
	for (int i = 1; i < n; ++ i) {
		if (i == (n - 1)) {
			if (check2(i + level)) {
				if (currStart[0] == 0)
					dp[i][1] = dp[i - 1][0] + map[i][1];
				if (currStart[0] < 2 && currStart[1] < 2)
					dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + map[i][2];
				else if (currStart[0] < 2)
					dp[i][2] = dp[i - 1][0] + map[i][2];
				else if (currStart[1] < 2)
					dp[i][2] = dp[i - 1][1] + map[i][2];
			} else {
				if (currStart[2] == 2)
					dp[i][1] = dp[i - 1][2] + map[i][1];
				if (currStart[1] > 0 && currStart[2] > 0)
					dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + map[i][0];
				else if (currStart[1] > 0)
					dp[i][0] = dp[i - 1][1] + map[i][0];
				else if (currStart[2] > 0)
					dp[i][0] = dp[i - 1][2] + map[i][0];
			}
		}
		if (check2(i + level)) {
			dp[i][1] = dp[i - 1][0] + map[i][1];
			currStart[1] = currStart[0];
			if (dp[i - 1][0] > dp[i - 1][1]) {
				dp[i][2] = dp[i - 1][0] + map[i][2];
				currStart[2] = currStart[0];
			} else {
				dp[i][2] = dp[i - 1][1] + map[i][2];
				currStart[2] = currStart[1];
			}
			currStart[0] = -1;
		} else {
			if (dp[i - 1][1] > dp[i - 1][2]) {
				dp[i][0] = dp[i - 1][1] + map[i][0];
				currStart[0] = currStart[1];
			} else {
				dp[i][0] = dp[i - 1][2] + map[i][0];
				currStart[0] = currStart[2];
			}
			dp[i][1] = dp[i - 1][2] + map[i][1];
			currStart[1] = currStart[2];
			currStart[2] = -1;
			// dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + map[i][0];
			// dp[i][1] = dp[i - 1][2] + map[i][1];
		}
	}
	
	int curr_max = max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
	maxn = max(maxn, curr_max);
	
	if (level) {
		level = 0;
		goto DO_SEARCH;
	}
	
	cout << maxn;
	return 0;
	
}