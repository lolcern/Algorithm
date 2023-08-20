#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

ll lazy[400003];
ll tree[400003];
ll a[100003];
int n;

void propagate(int s, int e, int node) {
	if (lazy[node]) {
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		tree[node] += (e - s + 1) * lazy[node];
		lazy[node] = 0;
	}
}

ll init(int s = 1, int e = n, int node = 1) {
	if (s == e) {
		return tree[node] = a[s];
	}
	int m = s + e >> 1;
	return tree[node] = init(s, m, node * 2) + init(m + 1, e, node * 2 + 1);
}

void update(int x, int y, int diff, int s = 1, int e = n, int node = 1) {
	propagate(s, e, node);
	if (x > e || y < s) return;
	if (s >= x && e <= y) {
		lazy[node] += diff;
		propagate(s, e, node);
		return;
	}
	int mid = s + e >> 1;
	update(x, y, diff, s, mid, node * 2);
	update(x, y, diff, mid + 1, e, node * 2 + 1);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int x, int s = 1, int e = n, int node = 1) {
	propagate(s, e, node);
	if (s > x || e < x) return 0;
	if (s == e && e == x) {
		return tree[node];
	}

	int mid = s + e >> 1;
	return query(x, s, mid, node * 2) + query(x, mid + 1, e, node * 2 + 1);

}

int main() {
	inp;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	init();

	while (m--) {
		int aa;
		cin >> aa;
		if (aa == 1) {
			int b, c, d;
			cin >> b >> c >> d;
			update(b, c, d);
		}
		else {
			int b;
			cin >> b;
			cout << query(b) << endl;
		}
	}

}