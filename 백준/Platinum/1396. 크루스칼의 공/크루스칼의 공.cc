#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int n;
int  m;
struct Edge {
	int c, a, b;

	bool operator<(const Edge& e) const {
		return c < e.c;
	}
};

vector<int> md[100003];
vector<int> tmp;
vector<Edge> line;
vector<p> q;
int lo[100003], hi[100003];
p ans[100003];

struct UF {
	int par[100003];
	int cnt[100003];

	UF() {
		for (int i = 1; i <= n; i++) {
			par[i] = i;
			cnt[i] = 1;
		}
	}

	int find(int x) {
		if (x == par[x])return x;
		else return par[x] = find(par[x]);
	}
	
	bool uni(int x,int y) {
		int a = find(x), b = find(y);
		if (a == b)return false;
		par[a] = b;
		cnt[b] += cnt[a];
		return true;
	}

	int count(int x) {
		int a = find(x);
		return cnt[a];
	}
};

int main() {
	inp;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		line.push_back({ c,a,b });
	}
	sort(line.begin(), line.end());
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		q.push_back({ a,b });
	}
	fill(hi, hi + Q, m + 1);

	while (1) {
		bool rst = false;
		for (int i = 1; i <= m; i++) {
			md[i].clear();
		}
		for (int i = 0; i < Q; i++) { //이분탐색
			if (lo[i] + 1 < hi[i]) {
				rst = true;
				md[(lo[i] + hi[i]) >> 1].push_back(i);
			}
		}
		if (!rst)break;

		UF uf;

		for (int i = 0; i < m; i++) {
			Edge now = line[i];
			uf.uni(now.a, now.b);

			for (auto a : md[i + 1]) {
				int u = uf.find(q[a].first), v = uf.find(q[a].second);
				if (u == v) {
					hi[a] = i + 1;
					ans[a].first = now.c;
					ans[a].second = uf.count(u);
				}
				else {
					lo[a] = i + 1;
				}
			}
		}
	}
	for (int i = 0; i < Q; i++) {
		if (lo[i] == m)cout << "-1" << endl;
		else cout << ans[i].first << " " << ans[i].second << endl;
	}
}