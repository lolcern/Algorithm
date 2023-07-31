#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

ll fact[200], factInv[200], mod = 1e9 + 7;

ll mpow(ll x, ll m) {
	if (!m) return 1;
	ll tmp = mpow(x, m / 2);
	tmp = tmp * tmp % mod;
	if (m % 2) return tmp * x % mod;
	return tmp;
}

ll Com(ll x, ll r) {
	return fact[x] * factInv[r] % mod * factInv[x - r] % mod;
}

ll dp[103][103];

int main() {
	inp;
	fact[0] = 1;
	for (int i = 1; i <= 100; i++) {
		fact[i] = fact[i - 1] * i % mod;
	}
	factInv[100] = mpow(fact[100], mod - 2);
	for (int i = 99; i >= 0; i--)factInv[i] = factInv[i + 1] * (i + 1) % mod;

	ll n, l, r;
	cin >> n >> l >> r;
	if (n == 1 && l == 1 && r == 1) {
		cout << "1";
		exit(0);
	}
	if ((l == r && l == 1) || (r + l) >= n+2) {
		cout << "0";
		exit(0);
	}
	dp[0][0] = 1;
	dp[1][1] = 1;
	dp[1][0] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][1] = fact[i - 1] % mod;
		dp[i][0] += dp[i][1];
		for (int j = 2; j < i; j++) {
			for (int k = j; k <= i; k++) {
				dp[i][j] += (dp[k - 1][j - 1] * dp[i - k][0]) % mod * Com(i - 1, k - 1) % mod;
				dp[i][j] %= mod;
			}
			dp[i][0] += dp[i][j];
			dp[i][0] %= mod;
		}
		dp[i][i] = 1;
		dp[i][0]++;
		dp[i][0] %= mod;
	}

	ll ans = 0;
	if (l == 1) {
		ans += dp[n - 1][r-1];
		cout << ans;
		exit(0);
	}
	if (r == 1) {
		ans += dp[n - 1][l - 1];
		cout << ans; 
		exit(0);
	}
	

	for (ll i = l; i <= n - r + 1; i++) {
		ans += (dp[i - 1][l - 1] * dp[n - i][r - 1]) % mod * Com(n - 1, i - 1) % mod;
		ans %= mod;
	}
	cout << ans;

}