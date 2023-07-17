#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000007
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int dp[53][53][53][53] = { 0, }; //dp[i][j][k][l] = (i,j)에서 k 를 마지막으로 ㅣ개의 오락실을 지났을때 경로의 수
int city[53][53] = { 0, };
int ans = 0;

int main() {
	inp;
	
	int n, m, c;
	cin >> n >> m >> c;

	for (int i = 1; i <= c; i++) {
		int u, v;
		cin >> u >> v;
		city[u][v] = i;
	}
	if (city[1][1] != 0) {
		dp[1][1][city[1][1]][1] = 1;
	}
	else {
		dp[1][1][0][0] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			//(i,j)가 오락실일때
			if (i == 1 && j == 1)continue;
			if (city[i][j] != 0) {

			for (int k = 0; k < city[i][j]; k++) {
				for (int l = 0; l <= k; l++) {
					dp[i][j][city[i][j]][l + 1] += dp[i - 1][j][k][l] + dp[i][j - 1][k][l];
					dp[i][j][city[i][j]][l + 1] %= MOD;
				}
			}
			}
			else {
			//(i,j)가 아무것도 아닐때
			for (int k = 0; k <= c; k++) {
				for (int l = 0; l <= k; l++) {
					dp[i][j][k][l] = (dp[i - 1][j][k][l] + dp[i][j - 1][k][l]) % MOD;
				}
			}
			}

			
		}
	}

	for (int i = 0; i <= c; i++) {
		ans = 0;
		for (int j = 0; j <= c; j++) {
			ans += dp[n][m][j][i];
			ans %= MOD;
		}
		cout << ans << " ";
	}
}