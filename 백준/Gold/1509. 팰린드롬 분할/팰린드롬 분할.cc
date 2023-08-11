#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

string a;
bool palin[2503][2503];
int dp[2503];



int main() {
	inp;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		palin[i][i] = true;
	}
	for (int i = 0; i < a.size() - 1; i++) {
		if (a[i] == a[i + 1]) {
			palin[i][i + 1] = true;
		}
		else {
			palin[i][i + 1] = false;
		}
	}
	for (int i = 2; i <= a.size()-1; i++) {
		for (int j = 0; j + i < a.size(); j++) {
			if (a[j] == a[j + i] && palin[j + 1][j + i - 1]) {
				palin[j][j + i] = true;
			}
		}
	}
	dp[0] = 1;

	for (int i = 1; i < a.size(); i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 0; j < i; j++) {
			if (palin[j][i]) {
				if (j == 0) {
					dp[i] = 1;
					break;
				}
				else {
					dp[i] = min(dp[i], dp[j - 1] + 1);
				}
			}
		}
	}

	cout << dp[a.size() - 1];
}