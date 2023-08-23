#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int n, a[300003];
int cnt;
bool up;
bool st;

int main() {
	inp;
	cin >> n;
	if (n >= 2) {
		cin >> a[1] >> a[2];
	}
	else {
		cin >> a[1];
		cout << "0";
		exit(0);
	}
	if (a[1] > a[2]) {
		up = false;
	}
	else up = true;
	st = up;
	cnt = 1;
	for (int i = 3; i <= n; i++) {
		cin >> a[i];
		if (a[i] > a[i - 1]) {
			if (!up) {
				up = true;
				cnt++;
			}
		}
		else if (a[i] < a[i - 1]) {
			if (up) {
				cnt++;
				up = false;
			}
		}
	}
	int ans = (int)log2(cnt);
	if (pow(2, ans) != cnt) {
		ans++;
	}
	else if (!st)ans++;
	cout << ans;

}