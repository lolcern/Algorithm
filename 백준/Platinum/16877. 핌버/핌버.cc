#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int gr[3000003];
int fibo[50];

int main() {
	inp;
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; fibo[i - 1] <= 3000000; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	gr[0] = 0;
	
	for (int i = 1; i <= 3000000; i++) {
		ll g = 0;
		for (int j = 1; fibo[j] <= i; j++) {
			g |= 1ll << gr[i - fibo[j]];
		}
		for (int j = 0; j <= 35; j++) {
			if (!(g & (1ll << j))) {
				gr[i] = j;
				break;
			}
		}
	}

	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		int b;
		cin >> b;
		ans ^= gr[b];
	}
	if (ans) cout << "koosaga";
	else cout << "cubelover";
}