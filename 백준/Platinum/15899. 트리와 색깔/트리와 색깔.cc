#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

vector<int> line[200003];
int a[200003];
int n, m, c;
int num[200003];
int num1[200003];
int ed[200003];
int cnt = 0;
ll ans;
vector<int> tree[800003];


void dfs(int now) {
	num[now] = ++cnt;
	num1[cnt] = now;
	for (auto b : line[now]) {
		if (!num[b]) dfs(b);
	}
	ed[now] = cnt;
}

void init(int s = 1, int e = n, int node = 1) {
	if (s == e) {
		tree[node].push_back(a[num1[s]]);
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

	cin >> n >> m >> c;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		line[u].push_back(v);
		line[v].push_back(u);
	}
	dfs(1);
	init();
	for (int i = 1; i <= m; i++) {
		int v, c;
		cin >> v >> c;
		ans += query(c, num[v], ed[v]);
		ans %= MOD;
	}

	cout << ans;

}

//왜안됨?