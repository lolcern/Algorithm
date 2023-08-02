#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;
int n;
int arr[1000003];
int tree[4000003];
int init(int st = 1, int ed = n, int node = 1) {
	if (st == ed)return tree[node] = arr[st];
	int mid = (st + ed) / 2;
	return tree[node] = max(init(st, mid, node * 2), init(mid + 1, ed, node * 2 + 1));
}

int query(int x, int y, int st = 1, int ed = n, int node = 1) {
	if (y < st || x > ed) return 0;
	if (st >= x && ed <= y) return tree[node];
	int mid = (st + ed) / 2;
	return max(query(x, y, st, mid, node * 2), query(x, y, mid + 1, ed, node * 2 + 1));
}

int main() {
	inp;
	int m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init();
	for (int i = m; i <= n - m + 1; i++) {
		cout << query(i - m + 1, i + m - 1) << " ";
	}
}