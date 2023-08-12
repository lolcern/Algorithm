#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 9901
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

char f[300];
int dp[200][1 << 14];
int n, m;
int price(char a, char b) {
	if (a == 'A') {
		if (b == 'A') return 10;
		if (b == 'B') return 8;
		if (b == 'C') return 7;
		if (b == 'D') return 5;
		if (b == 'F') return 1;
	}
	if (a == 'B') {
		if (b == 'A') return 8;
		if (b == 'B') return 6;
		if (b == 'C') return 4;
		if (b == 'D') return 3;
		if (b == 'F') return 1;
	}
	if (a == 'C') {
		if (b == 'A') return 7;
		if (b == 'B') return 4;
		if (b == 'C') return 3;
		if (b == 'D') return 2;
		if (b == 'F') return 1;
	}
	if (a == 'D') {
		if (b == 'A') return 5;
		if (b == 'B') return 3;
		if (b == 'C') return 2;
		if (b == 'D') return 2;
		if (b == 'F') return 1;
	}
	if (a == 'F') {
		if (b == 'A') return 1;
		if (b == 'B') return 1;
		if (b == 'C') return 1;
		if (b == 'D') return 1;
		if (b == 'F') return 0;
	}
	return 0;
}

int go(int idx, int stat) {
	int& ans = dp[idx][stat];
	if (idx >= n * m) {
		if (idx == n * m && stat == 0) {
			return 0;
		}
		return -1000000;
	}
	if (ans != -1) {
		return ans;
	}

	ans = max(0,go(idx + 1, stat >> 1));
	if (!(stat & 1)) {
		if (idx % m != m - 1 && !(stat & (1 << 1))) { //오른쪽 블록을 채울때
			ans = max(ans, go(idx + 2, stat >> 2) + price(f[idx],f[idx + 1]));
		}
		//아래 블록을 채울때
		ans = max(ans, go(idx + 1, (stat >> 1) | (1 << m - 1)) + price(f[idx],f[idx + m]));
	}
	return dp[idx][stat] = ans;
}

int main() {
	inp;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> f[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0);
}