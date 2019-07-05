#include <iostream>
#include <cmath>
#include <queue>
#include <cstdio>
#include <map>

using namespace std;

long long threeN[34] = {0};

inline bool checkNotAccessed(long long v, int i) {
	return !(v & (1 << i));
}

inline long long setAccessed(long long v, int i) {
	return (v | (1 << i));
}

inline int getStart(long long n, long long curr) {
	long long delta = abs(n - curr);
	if (delta < threeN[10]) return 0;
	else if (delta < threeN[20]) return 10;
	else if (delta < threeN[30]) return 20;
	else return 30;
}
inline int getEnd(long long n, long long curr) {
	long long delta = abs(n - curr);
	if (delta < threeN[10]) return 10;
	else if (delta < threeN[20]) return 20;
	else if (delta < threeN[30]) return 30;
	else return 34;
}

struct Node {
	unsigned long plus;
	unsigned long minus;
	long long current;
	Node (int _pl, int _mi, int _curr) {
		plus = _pl, minus = _mi, current = _curr;
	}
};

map<long long, bool> vis;

Node bfs(long long n) {
	queue<Node> q;
	q.push(Node(0, 0, 0));
	while (!q.empty()) {
		Node curr = q.front(); q.pop();
		if (curr.current == n) return curr;
		if (vis[curr.current]) continue;
		vis[curr.current] = true;
		for (register int i = getStart(n, curr.current); i < getEnd(n, curr.current); ++ i) {
			if (checkNotAccessed(curr.plus, i) && checkNotAccessed(curr.minus, i)) {
				if ((n - curr.current) > 0)
					q.push(Node(setAccessed(curr.plus, i), curr.minus, curr.current + threeN[i]));
				else
					q.push(Node(curr.plus, setAccessed(curr.minus, i), curr.current - threeN[i]));
			}
		}
	}
}

int main() {
	
	freopen("entertain.in", "r", stdin);
	freopen("entertain.out", "w", stdout);
	
	threeN[0] = 1;
	for (register int i = 1; i < 34; ++ i) threeN[i] = 3 * threeN[i - 1];
	
	long long n;
	cin >> n;
	
	Node rslt = bfs(n); bool flag = false;
	
	for (register int i = 0; i < 31; ++ i) if ((rslt.plus >> i) & 1) {
		if (flag) cout << " ";
		else flag = true;
		cout << threeN[i];
	}
	cout << endl << n;
	for (register int i = 0; i < 31; ++ i) if ((rslt.minus >> i) & 1) cout << " " << threeN[i];
	
	return 0;
	
}