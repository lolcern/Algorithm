#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

struct lz {
	ll ml; ll pl;
	lz() {
		ml = 1;
		pl = 0;
	}
};

ll tree[400003];
lz lazy[400003];
ll ar[100003];
int n;

ll init(int s = 1, int e = n, int node = 1) {
	if (s == e)return tree[node] = ar[s];
	int m = s + e >> 1;
	return tree[node] = (init(s, m, node * 2) + init(m + 1, e, node * 2 + 1))%MOD;
}

void propagate(int s, int e, int node) {
	if (lazy[node].ml != 1 || lazy[node].pl != 0) {
		tree[node] *= lazy[node].ml;
		tree[node] += (e - s + 1) * lazy[node].pl;
		tree[node] %= MOD;
		if (s != e) {
			for (auto a : { node * 2,node * 2 + 1 }) {
				lazy[a].ml *= lazy[node].ml;
				lazy[a].ml %= MOD;
				lazy[a].pl *= lazy[node].ml;
				lazy[a].pl %= MOD;
				lazy[a].pl += lazy[node].pl;
				lazy[a].pl %= MOD;
			}
		}
	}
	lazy[node].ml = 1;
	lazy[node].pl = 0;
}

void update(int x, int y, ll ml, ll pl, int s = 1, int e = n, int node = 1) {
	propagate(s, e, node);
	if (x > e || s > y) {
		return;
	}
	if (x <= s && e <= y) {
		lazy[node].ml *= ml;
		lazy[node].ml %= MOD;
		lazy[node].pl *= ml;
		lazy[node].pl %= MOD;
		lazy[node].pl += pl;
		lazy[node].pl %= MOD;
		propagate(s, e, node);
		return;
	}
	int m = s + e >> 1;
	update(x, y, ml, pl, s, m, node * 2);
	update(x, y, ml, pl, m+1, e, node * 2+1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	tree[node] %= MOD;
}

ll query(int x, int y, int s = 1, int e = n, int node = 1) {
	propagate(s, e, node);
	if (x > e || s > y) {
		return 0;
	}
	if (x <= s && e <= y) {
		return tree[node];
	}
	int m = s + e >> 1;
	return (query(x, y, s, m, node * 2) + query(x, y, m + 1, e, node * 2 + 1))%MOD;
}

int main() {
	inp;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	init();
	int k;
	cin >> k;
	while (k--) {
		int a;
		cin >> a;
		if (a == 4) {
			int b, c;
			cin >> b >> c;
			cout << query(b, c) % MOD << endl;
		}
		else {
			int b, c, d;
			cin >> b >> c >> d;
			if (a == 1)update(b, c, 1, d);
			if (a == 2)update(b, c, d, 0);
			if (a == 3)update(b, c, 0, d);
		}
	}
}