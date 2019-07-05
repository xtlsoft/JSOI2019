/* Result: AC 100 */
#include <iostream>
#include <queue>
#include <cmath>
#include <cstdio>
#include <map>
#define qp(ax, bx, cx) q.push(Node(curr.depth + 1, curr.a + (ax), curr.b + (bx), curr.c + (cx))); \
	q.push(Node(curr.depth + 1, curr.a - (ax), curr.b - (bx), curr.c - (cx)))

using namespace std;

struct Node {
	int depth;
	int a;
	int b;
	int c;
	Node(int _d, int _a, int _b, int _c) {
		depth = _d, a = _a, b = _b, c = _c;
	}
};

map<pair<int, pair<int, int> >, bool> vis;

int bfs(int n, int a, int b, int c) {
	queue<Node> q;
	q.push(Node(0, 0, 0, 0));
	while (!q.empty()) {
		Node curr = q.front(); q.pop();
		if (curr.depth > n) return -1;
		if (curr.a == a && curr.b == b && curr.c == c && curr.depth != 0) return curr.depth;
		if (vis[make_pair(curr.a, make_pair(curr.b, curr.c))]) continue;
		vis[make_pair(curr.a, make_pair(curr.b, curr.c))] = true;
		/*********** Start Status ***********/
		for (int i = 1; i <= 3; ++ i) {
			int j = 0 - i * 2;
			qp(i, i, j);
			qp(i, j, i);
			qp(j, i, i);
		}
		/************ End Status ************/
	}
}

int main() {
	
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	
	if ((a != 0 && b != 0 && c != 0) && (a == b || b == c || a == c)) {
		int maxn = max(abs(a), max(abs(b), abs(c)));
		int rn = ceil(maxn*1.0 / 6.0);
		if (rn > n) rn = -1;
		cout << rn;
		return 0;
	}
	
	cout << bfs(n, a, b, c);
	
	return 0;
	
}