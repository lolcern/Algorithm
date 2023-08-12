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
		if (b == 'A') return 100;
		if (b == 'B') return 70;
		if (b == 'C') return 40;
	}
	if (a == 'B') {
		if (b == 'A') return 70;
		if (b == 'B') return 50;
		if (b == 'C') return 30;
	}
	if (a == 'C') {
		if (b == 'A') return 40;
		if (b == 'B') return 30;
		if (b == 'C') return 20;
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
	cin >> n;
	m = n;
	for (int i = 0; i < n * m; i++) {
		cin >> f[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0);
}