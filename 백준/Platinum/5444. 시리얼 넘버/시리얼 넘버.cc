#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int dp[2][100003]; //dp[0][j] : j를 만들 수 있는 최대 기타의 개수
int arr[503];


int main() {
	inp;
	int t;
	cin >> t;
	while (t--) {
		//초기화
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			arr[i] %= m;
		}
		dp[1][arr[1]] = 1;

		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (dp[(i+1) & 1][j]) {
					dp[i & 1][(j + arr[i]) % m] = max(dp[i & 1][(j + arr[i]) % m], dp[(i + 1) & 1][j] + 1);
					dp[i & 1][j] = max(dp[(i + 1) & 1][j], dp[i & 1][j]);
				}
			}
			dp[i&1][arr[i]] = max(1, dp[i&1][arr[i]]);
		}

		cout << dp[n & 1][0] << endl;
	}
}