#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int gr[1003];
bool ex[1003];

int main() {
	inp;
	
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		fill(ex, ex + 1003, false);
		for (int j = 0; j <= (i - 2)/2; j++) {
			ex[(gr[j] ^ gr[i - 2 - j])] = true;
		}
		int num = 0;
		while (ex[num])num++;
		gr[i] = num;
	}
	if (gr[n]) {
		cout << "1";
	}
	else {
		cout << "2";
	}
}