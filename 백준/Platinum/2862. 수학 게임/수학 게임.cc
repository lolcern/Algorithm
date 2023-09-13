#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

ll fibo[100];



int main() {
	inp;
	fibo[1] = 1;
	for (int i = 2; i < 90; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	ll n;
	cin >> n;
	for (int i = 89; i >= 0; i--) {
		if (fibo[i] == n) {
			cout << n;
			exit(0);
		}
		if (fibo[i] < n) {
			n -= fibo[i];
		}
	}
}