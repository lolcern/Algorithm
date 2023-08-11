#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 9901
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int dp[200][1 << 14];
	int n, m;

int go(int idx, int stat) {
	if (idx >= n * m) {
		if (idx == n * m && stat == 0) {
			return 1;
		}
		return 0;
	}
	if (dp[idx][stat] != -1) {
		return dp[idx][stat];
	}
	int ans = 0;
	if (stat & 1) {
		ans += go(idx + 1, stat >> 1);
	}
	else {
		if (idx % m != m - 1 && !(stat & (1 << 1))) { //오른쪽 블록을 채울때
			ans += go(idx + 2, stat >> 2);
		}
		//아래 블록을 채울때
		ans += go(idx + 1, (stat >> 1) | (1 << m - 1));
	}
	return dp[idx][stat] =  ans % MOD;
}

int main() {
	inp;
	cin >> n >> m;
	if (n * m & 1) {
		cout << "0"; exit(0);
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0);
}