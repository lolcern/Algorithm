#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

vector<int> line[503];
vector<int> tmp;
int c[503][503];
int f[503][503];
int pre[503];

int nflow(int s, int e) {
	int ans = 0;
	while (1) {
		memset(pre, 0, sizeof(pre));
		queue<int> q;
		q.push(s);
		while (!q.empty() && pre[e] == 0) {
			int now = q.front();
			q.pop();
			for (auto nxt : line[now]) {
				if (c[now][nxt] > f[now][nxt] && pre[nxt] == 0) {
					q.push(nxt);
					pre[nxt] = now;
					if (nxt == e)break;
				}
			}
		}
		if (!pre[e])break;

		int flow = INF;
		for (int i = e; i != s; i = pre[i]) {
			flow = min(flow, c[pre[i]][i] - f[pre[i]][i]);
		}
		for (int i = e; i != s; i = pre[i]) {
			f[pre[i]][i] += flow;
			f[i][pre[i]] -= flow;
		}
		ans += flow;
	}
	return ans;
}

int main() {
	inp;

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b, cc;
		cin >> a >> b >> cc;
		c[a][b] = cc;
		c[b][a] = cc;
		line[a].push_back(b);
		line[b].push_back(a);
	}

	int s, e;
	cin >> s >> e;
	cout << nflow(s, e);

}