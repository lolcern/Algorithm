#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int n, m;
ll tree[4000003];
int arr[1000003];

void update(int x, int diff, int st = 1, int ed = n, int node = 1) {
	if (st <= x && ed >= x) {
		tree[node] += diff;
		if (st == ed) return;
		int mid = (st + ed) / 2;
		update(x, diff, st, mid, node*2);
		update(x, diff, mid + 1, ed, node*2+1);
	}
}

ll query(int x, int y, int st = 1, int ed = n, int node = 1) {
	if (st > y || ed < x) {
		return 0;
	}
	if (st >= x && ed <= y) {
		return  tree[node];
	}
	int mid = (st + ed) / 2;
	return query(x, y, st, mid, node * 2) + query(x, y, mid + 1, ed, node * 2 + 1);
}

int main() {
	inp;
	cin >> n >> m;

	while (m--) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c - arr[b]);
			arr[b] = c;
		}
		else {
			cout << query(min(b,c), max(b,c)) << endl;
		}
	}

}