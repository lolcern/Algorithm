#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;



int main() {
	inp;
	int t;
	cin >> t;
	while (t--) {
		int pl = 0, mi = 0;
		int n;
		ll sum = 0;
		cin >> n;
		while (n--) {
		ll a;
			cin >> a;
			if (a < 0) {
				if (sum > 0 && sum + a <= 0) {
					pl++;
					sum = 0;
				}
			}
			else if (a > 0) {
				if (sum < 0 && sum + a <= 0) {
					mi++;
					sum = 0;
				}
				if (sum > 0) {
					pl++;
					sum = 0;
				}
			}
			sum += a;
		}
		if (sum > 0) {
			pl++;
		}
		if (sum < 0) {
			mi++;
		}
		if (pl > mi) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}