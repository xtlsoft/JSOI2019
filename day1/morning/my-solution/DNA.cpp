/* Result: TLE 80 */
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string DNA;
int hashmap[1048578] = {0};

int hash_func(int start, int length) {
	int rslt = 0;
	for (int i = 0; i < length; ++ i) {
		rslt *= 4;
		char curr = DNA[start + i];
		switch (curr) {
			case 'A':
				rslt += 0;
				break;
			case 'C':
				rslt += 1;
				break;
			case 'G':
				rslt += 2;
				break;
			case 'T':
				rslt += 3;
				break;
			default:
				break;
		}
	}
	return rslt;
}

int main() {
	
	freopen("DNA.in", "r", stdin);
	freopen("DNA.out", "w", stdout);
	
	int length;
	cin >> DNA >> length;
	
	for (int i = 0; i <= (DNA.length() - length); ++ i) {
		hashmap[hash_func(i, length)] ++;
	}
	
	int maxn = 0;
	
	for (int i = 0; i < 1048578; ++ i) {
		maxn = max(maxn, hashmap[i]);
	}
	
	cout << maxn;
	
	return 0;
	
}