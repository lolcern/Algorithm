#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;



int main() {
	inp;
	int n;
	int one = 0;
	int dols[103];
	cin >> n;
	int x = 0;
	for(int i = 1; i <= n; i++) {
		cin >> dols[i];
		if (dols[i] == 1)one++;
	}
	if (one == n) {
		if (one & 1) {
			cout << "cubelover";
		}
		else {
			cout << "koosaga";
		}
	}
	else {
		if (one > 0 && !(one & 1)) {
			for (int i = 1; i <= n; i++) {
				if (dols[i] > 1)dols[i] = 1;
				break;
			}

		}
		int tmp =0;
		for (int i = 1; i <= n; i++) {
			tmp ^= dols[i];
		}
		if (tmp) {
			cout << "koosaga";
		}
		else {
			cout << "cubelover";
		}
	}
	

}