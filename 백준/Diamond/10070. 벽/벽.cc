#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair < ll, ll > p;

int n,k;
p tree[1 << 22]; //first : 최소, second : 최대
ll wall[2000003];

void propagate(int op, ll h, int node) {
	if (op == 1) {
		tree[node].first = max(tree[node].first, h);
		tree[node].second = max(tree[node].second, h);
	}
	else {
		tree[node].first = min(tree[node].first, h);
		tree[node].second = min(tree[node].second, h);
	}
}

void update(int x,int y,int op,ll h,int s = 1,int e = n,int node = 1) {
	if (y < s || e < x) {
		return;
	}
	if (x <= s && e <= y) {
		propagate(op, h, node);
		if (s == e) {
			wall[s] = tree[node].first;
		}
		return;
	}
	for (auto a : { node * 2,node * 2 + 1 }) {
		propagate(1, tree[node].second, a);
		propagate(2, tree[node].first, a);
	}
	tree[node] = { 1e9,0 };
	int m = s + e >> 1;
	update(x, y, op, h, s, m, node * 2);
	update(x, y, op, h, m+1, e, node * 2+1);

}

int main() {
	inp;
	cin >> n >> k;
	while (k--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		update(b+1, c+1, a, d);
	}
	for (int i = 1; i <= n; i++) {
		update(i, i, 1, 0);
		cout << wall[i] << endl;
	}
	
}