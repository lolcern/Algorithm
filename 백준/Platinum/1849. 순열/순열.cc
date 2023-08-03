#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int n;
int ans[100003];
int tree[300000];

int init(int x = 1, int y = n, int node = 1) {
	if (x == y)return tree[node] = 1;
	int mid = (x + y) / 2;
	return tree[node] = init(x, mid, node * 2) + init(mid+1, y, node * 2 + 1);
}

void update(int x, int st = 1, int ed = n, int node = 1) {
	if (st == ed && st == x) {
		tree[node] = 0;
		return;
	}
	if (st <= x && ed >= x) {
		tree[node]--;

		int mid = (st + ed) / 2;
		update(x, st, mid, node * 2);
		update(x, mid + 1, ed, node * 2 + 1);
	}
}

int query(int x) {
	int st = 1;
	int ed = n;
	int node = 1;
	while (st != ed) {
		if (tree[node * 2] < x) {
			x -= tree[node * 2];
			int mid = (st + ed) / 2;
			st = mid+1;
			node = node * 2 + 1;
		}
		else {
			int mid = (st + ed) / 2;
			ed = mid;
			node = node * 2;
		}
	}
	return st;
}




int main() {
	inp;
	cin >> n;
	init();
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		int b = query(a + 1);
		ans[b] = i;
		update(b);
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
	
}