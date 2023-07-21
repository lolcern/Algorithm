#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

ll a[100003];
ll sum;
ll ans;
int n;

int dfs(int num=0,int cnt=0) {
	ll tsum = 0;
	for (int i = num + 1; i <= n; i++) {
		tsum += a[i];
		if (tsum == sum) {
			if (cnt == 3) {
				ans++;
			}
			else
			dfs(i, cnt + 1);
		}
	}
	return 0;
}

int main() {
	inp;

	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % 4 != 0) {
		cout << "0";
		return 0;
	}
	else {
		sum /= 4;
		dfs();
	}
	cout << ans;
}