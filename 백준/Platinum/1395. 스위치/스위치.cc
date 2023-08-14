#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;
const int sz = 1 << 21;

int n,m,k;
ll tree[4000003];
ll lazy[4000003];
ll arr[1000003];


void propagate(int s, int e, int node) {
	if (lazy[node]) {
		if (s != e) {
			lazy[node * 2] ^= 1;
			lazy[node * 2 + 1] ^= 1;
		}
		tree[node] = e - s + 1 - tree[node];
		lazy[node] = 0;
	}
}

void update(int x,int y,int s = 1,int e = n, int node = 1) {
	propagate(s, e, node);
	if (x > e || y < s)return;
	if (s >= x && e <= y) {
		lazy[node] ^= 1;
		propagate(s, e, node);
		return;
	}
	int mid = s + e >> 1;
	update(x, y, s, mid, node * 2);
	update(x, y, mid + 1, e, node * 2 + 1);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int x, int y, int s = 1, int e = n, int node = 1) {
	propagate(s, e, node);
	if (x > e || y < s) return 0;
	if (s >= x && e <= y) {
		return tree[node];
	}
	int mid = s + e >> 1;
	return query(x, y, s, mid, node * 2) + query(x, y, mid + 1, e, node * 2 + 1);
}



int main() {
	inp;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a) {
			cout << query(b, c) << endl;
		}
		else {
			update(b, c);
		}
	}

}