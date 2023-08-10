#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int k, m, mod;
int arr[10000002];
int num = 1;

void dfs(int a) {
	while (arr[a] < k) {
		ll nxt = (ll)a * k % mod;
		nxt += arr[a];
		arr[a]++;
		dfs(nxt);
	}
	if (num <= mod * k) {
		cout << a % k << " ";
		num++;
	}
}

int main() {
	inp;
	cin >> k >> m;
	if (m == 1) {
		for (int i = 0; i < k; i++) {
			cout << i << " ";
		}
		exit(0);
	}
	mod = pow(k, m - 1);
	dfs(0);
}


/*
* 000 ->
* 000 001 002 003... 00(k-1)
* 001 ->
* 010 011 012 013... 01(k-1)
* ...
* 
*/