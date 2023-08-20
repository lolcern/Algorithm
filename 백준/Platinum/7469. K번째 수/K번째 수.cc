#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int n, arr[100003];
vector<int> tree[400003];

void init(int s = 1,int e = n,int node = 1) {
	if (s == e) {
		tree[node].push_back(arr[s]);
		return;
	}
	int m = s + e >> 1;
	init(s, m, node * 2);
	init(m + 1, e, node * 2 + 1);
	vector<int>& l = tree[node * 2];
	vector<int>& r = tree[node * 2 + 1];

	tree[node].resize(l.size() + r.size());	
	merge(l.begin(), l.end(), r.begin(), r.end(), tree[node].begin());
}

int query(int k, int x, int y, int s = 1, int e = n, int node = 1) {
	if (x > e || y < s) {
		return 0;
	}
	if (x <= s && e <= y) {
		return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
	}
	int m = s + e >> 1;
	return query(k, x, y, s, m, node * 2) + query(k, x, y, m + 1, e, node * 2 + 1);
}

int main() {
	inp;
	int m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init();
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		int s = -1e9, e = 1e9;
		int r = 0;
		while (s <= e) {
			int m = s + e >> 1;
			int ans = query(m, a, b);
			if (ans >= c) {
				r = m;
				e = m - 1;
			}
			else {
				s = m + 1;
			}
		}
		cout << r << endl;

	}
}