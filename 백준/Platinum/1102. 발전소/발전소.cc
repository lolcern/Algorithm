#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
#define INF 10000000
using namespace std;
typedef long long int ll;

int dp[1 << 18];
int n, p;
int gr[18][18];
char st[18];
int ans = INF;

void go(int cost, int stat, int cnt) { // cost : 얼마만큼, stat : 어떤 상태, cnt : 몇개
	if (cnt >= p) { //다 켰으면.
		ans = min(cost, ans);
		return;
	}
	if (dp[stat] <= cost) {
		return;
	}
	dp[stat] = cost;

	for (int i = 1; i <= n; i++) {
		if (!(stat & 1 << i)) {
			int m = 40;
			for (int j = 1; j <= n; j++) {
				if (stat & (1 << j)) {
					m = min(m, gr[j][i]);
				}
			}
			go(cost + m, stat | 1 << i, cnt + 1);
		}
	}

}

int main() {
	inp;
	fill(dp, dp + (1 << 18), INF);
	cin >> n;
	int first = 0;
	int firstn = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> gr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> st[i];
		if (st[i] == 'Y') {
			first |= 1 << i;
			firstn++;
		}
	}
	cin >> p;

	if (firstn == 0 && p != 0) {
		cout << "-1";
		exit(0);
	}
	go(0, first, firstn);

	if (ans == INF) {
		cout << "-1";
		exit(0);
	}
	cout << ans;

}