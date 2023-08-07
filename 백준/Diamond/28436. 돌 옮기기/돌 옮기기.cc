#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;



int main() {
	inp;
	int  t;
	cin >> t;
	while (t--) {
		string a;
		ll m = 0;
		int num = 0;
		cin >> a;
		char now = 'n'; //n : 아무것도 아님
		for (int i = a.size() - 1; i >= 0; i--) {
			char n = a[i];
			if (n == '.') {
				if (now == 'n')continue;
				m += (now == 'W' ? 1 : -1) * num;
			}
			else {
				if (now == 'n') {
					num = 1;
					now = n;
				}
				else if (now == n) {
					num++;
				}
				else {
					num = 0;
					now = 'n';
				}
			}
		}
			if (m > 0)cout << "WHITE\n";
			else cout << "BLACK\n";
	}

}