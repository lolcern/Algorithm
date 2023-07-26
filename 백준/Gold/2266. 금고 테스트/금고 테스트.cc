#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int dp[503][503];

int main() {
	inp;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		dp[1][i] = i;
	}
	for (int i = 2; i <= k; i++) { //금고 개수
		for (int j = 1; j <= n; j++) { //층 수
			if (i > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = INF;
				for (int l = 1; l <= j; l++) { //l 층에서 떨어뜨렸을때
					dp[i][j] = min(dp[i][j], 1 + max(dp[i - 1][l - 1], dp[i][j - l]));
				}
			}
			
		}
	}
	cout << dp[k][n];
}