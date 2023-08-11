#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define inf -1000000000000000
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

ll tree[400003];
int n, d;

void update(int x, ll diff, int st = 1, int ed = n, int node = 1) {
	if (st <= x && ed >= x) {
		tree[node] = max(tree[node],diff);
		if (st == ed) return;
		int mid = (st + ed) / 2;
		update(x, diff, st, mid, node * 2);
		update(x, diff, mid + 1, ed, node * 2 + 1);
	}
}

ll query(int x, int y, int st = 1, int ed = n, int node = 1) {
	if (x > ed || y < st) return inf;
	if (st >= x && ed <= y)return tree[node];
	int mid = (st + ed) / 2;
	return max(query(x, y, st, mid, node * 2), query(x, y, mid + 1, ed, node * 2 + 1));
}

ll arr[100003];

int main() {
	inp;
	for (int i = 1; i <= 400000; i++) {
		tree[i] = inf;
	}

	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	update(1, arr[1]);
	
	for (int i = 2; i <= n; i++) {
		ll a = max(0ll, query(max(1, i - d), i - 1)) + arr[i];
		update(i, a);
	}
	cout << query(1, n) << endl;
}