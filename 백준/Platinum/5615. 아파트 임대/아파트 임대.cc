#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef unsigned long long int ll;

ll power(ll a, ll r, ll mod) {
	ll res = 1;
	a %= mod;
	while (r) {
		if (r % 2)res = (res * a) % mod;
		r /= 2;
		a = (a * a) % mod;
	}
	return  res;
}

ll aa[3] = { 2,7,61 };

bool ispr(ll n) {
	
	for (ll a : aa) {
		if (n % a == 0) return false;
		ll k = n - 1;
		while (1) {
			ll tmp = power(a, k, n);
			if (tmp == n - 1) break;
			if (k % 2) {
				if (tmp == 1 || tmp == n - 1) {
					break;
				}
				else {
					return false;
				}
			}
			k /= 2;
		}
	}
	return true;
}

int main() {
	inp;
	int ans = 0;
	ll rrr;
	int nn;
	cin >> nn;

	while (nn--) {
		cin >> rrr;
		if (rrr * 2 + 1 == 7 || rrr * 2 + 1 == 61) {
			ans++;
			continue;
		}
		if (ispr(rrr * 2 + 1)) {
			ans++;
		}
	}
	cout << ans;
	

}