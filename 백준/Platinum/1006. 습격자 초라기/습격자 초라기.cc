#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int n, k;
int dp[10003];
int a[10003];
int b[10003];
int o[2][10003];

void go(int st) {
	for (int i = st; i <= n; i++) {
		dp[i] = min(a[i - 1], b[i - 1]) + 1;
		if (o[0][i-1] + o[1][i-1] <= k) {
			dp[i] = min(dp[i - 1] + 1, dp[i]);
		}
		if (i > 1 && o[0][i - 2] + o[0][i - 1] <= k && o[1][i - 1] + o[1][i - 2] <= k) {
			dp[i] = min(dp[i], dp[i - 2] + 2);
		}
		
		if (i != n) {
			a[i] = dp[i] + 1;
			if (o[0][i] + o[0][i - 1] <= k) {
				a[i] = min(a[i], b[i-1] + 1);
			}
			b[i] = dp[i] + 1;
			if (o[1][i] + o[1][i - 1] <= k) {
				b[i] = min(b[i], a[i-1] + 1);
			}
		}
	}
}

int main() {
	inp;
	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(o, 0, sizeof(o));
		int ans;
		cin >> n >> k;
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < n; i++) {
				cin >> o[j][i];
			}
		}

		if (n == 1)
		{
			cout << ((o[0][0] + o[1][0] <= k) ? 1 : 2) << endl;
			continue;
		}

		dp[0] = 0;
		a[0] = 1;
		b[0] = 1;
		go(1);
		ans = dp[n];
		
		//위만 채울때
		// xo
		// oo
		if(o[0][0] + o[0][n-1] <= k){
			dp[1] = 1;
			a[1] = 2;
			b[1] = o[1][0] + o[1][1] <= k ? 1 : 2;
			go(2);
			ans = min(ans, b[n - 1] + 1);
		}

		//아래만 채울때
		//oo
		//xo
		if (o[1][0] + o[1][n - 1] <= k) {
			dp[1] = 1;
			a[1] = o[0][0] + o[0][1] <= k ? 1 : 2;
			b[1] = 2;
			go(2);
			ans = min(ans,a[n - 1] + 1);
		}

		//둘다 채울때
		//xo
		//xo
		if (o[1][0] + o[1][n - 1] <= k && o[0][0] + o[0][n - 1] <= k) {
			dp[1] = 0;
			a[1] = 1;
			b[1] = 1;
			go(2);
			ans = min(ans, dp[n - 1] + 2);
		}
		cout << ans << endl;
	}

}