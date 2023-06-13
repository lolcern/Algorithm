#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;

vector<int> dp;
int a;
int n;

void bin(int x) {
	int u = 1;
	int v = dp.size() - 1;
	int here = 99999999;
	if (dp[dp.size() - 1] < x) {
		dp.push_back(x);
		return;
	}
	else if (dp[1] > x) {
		dp[1] = x;
		return;
	}
	while (u <= v) {
		int mid = (u + v) / 2;
		if (dp[mid] > x) {
			v = mid - 1;
			here = min(mid, here);
		}
		else if (dp[mid] < x) {
			u = mid + 1;
		}
		else {
			return;
		}
	}
	dp[here] = x;
}

int main() {
	int t;
	cin >> t;

	for (int asdf = 1; asdf <= t; asdf++) {
			dp.clear();
		dp.push_back(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		bin(a);
	}
	cout << dp.size() - 1 << endl;
	}
	
}