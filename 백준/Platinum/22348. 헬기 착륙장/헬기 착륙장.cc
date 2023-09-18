#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int dp[503][50003];

int main() {
	inp;
	
	dp[0][0] = 1;
	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 50000; j++) {
			dp[i + 1][j] += dp[i][j]; // 원이 한개 더 추가될때 파란색씀
			dp[i + 1][j] %= MOD;
			if (j + i + 1 <= 50000) {
				dp[i + 1][j + i + 1] += dp[i][j];//빨간색 씀
				dp[i + 1][j + i + 1] %= MOD;
			}
			
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int r, b;
		int ans = 0;
		cin >> r >> b;
		for (int i = 1; i * (i+1) <= 2 * (r+b); i++) {
			//이거 누적합으로 묶어야함
			for (int j = 0; j <= r; j++) {
				if ((i * (i + 1)) / 2 - j <= b) {
					ans += dp[i][j];
					ans %= MOD;
				}
			}
		}
		cout << ans << endl;
	}

}