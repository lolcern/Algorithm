#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long ll;



int main() {
	inp;

	ll q;

	ll m, M;
	m = -1000000000000000001;
	M = 1000000000000000001;
	int mos=0;
	int corr = 0;
	cin >> q;

	for (int i = 1; i <= q; i++) {
		ll a; char b;
		cin >> a >> b;
		if (b == '^') {
			m = max(a,m);
			if (m >= M-1 && mos == 0) {
				mos = i;
			}
			else if (m == M - 2 && corr == 0) {
				corr = i;
			}
		}
		else {
			M = min(M,a);
			if (m >= M-1 && mos == 0) {
				mos = i;
			}
			else if (m == M - 2 && corr == 0) {
				corr = i;
			}
		}
	}

	if (mos != 0) {
		cout << "Paradox!" << endl;
		cout << mos;
	}
	else {
		if (corr != 0) {
			cout << "I got it!" << endl;
			cout << corr;
		}
		else {
			cout << "Hmm...";
		}
	}

}