#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int c[3001][3001], f[3001][3001];
vector<int> line[3001];
int pre[3001];
int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 0,0,0,1,-1 };

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
	int t;
	cin >> t;
	while (t--) {
		for (int i = 1; i <= 3000; i++) {
			line[i].clear();
		}
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		int sum = 0;
		int n, m;
		cin >> n >> m;
		int s = n * m + 1, e = n * m + 2;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int a;
				cin >> a;
				sum += a;
				if (i % 2 == j % 2) {
					line[s].push_back((i - 1) * m + j);
					c[s][(i - 1) * m + j] = a;

					for (int k = 1; k <= 4; k++) {
						int x = dx[k] + i;
						int y = dy[k] + j;
						if (x >= 1 && x <= n && y >= 1 && y <= m) {
							c[(i - 1) * m + j][(x - 1) * m + y] = 1000000000;
							line[(i - 1) * m + j].push_back((x - 1) * m + y);
							line[(x - 1) * m + y].push_back((i - 1) * m + j);
						}
					}
				}
				else {
					line[(i - 1) * m + j].push_back(e);
					c[(i - 1) * m + j][e] = a;
				}
				
			}
		}
		cout << sum - nflow(s, e) << endl;
	}

	

}