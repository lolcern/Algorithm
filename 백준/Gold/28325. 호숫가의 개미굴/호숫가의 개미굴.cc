#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

ll ans;

int main() {
	inp;
	ll st = 0;
	ll now = 0;
	ll n;
	bool aaaa = true;
	cin >> n;
	
	while (n--) {
		ll a;
		cin >> a;
		if (a == 0) { 
			now++;
			if (aaaa)st++;
		}
		else { 
			ans += a;
			aaaa = false;
			now++;
			ans += (now / 2);
			now = 0;
		}

	}
	if (aaaa) {
		ans += (st) / 2;
	}
	else ans += (st + now + 1) / 2;

	cout << ans;
}