#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int c[301][301], f[301][301];
vector<int> line[301];
vector<p> linelist;
vector<int> tmp;
int pre[301];

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

bool checkline(int s, int e) {
	queue<int> q;
	q.push(s);
	memset(pre, 0, sizeof(pre));
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
	return !pre[e];
}

int main() {
	inp;
	int t;
	cin >> t;
	while (t--) {
		linelist.clear();
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		int n, m;
		int Ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			line[i] = tmp;
		}

		for (int i = 1; i <= m; i++) {
			int a, b, cc;
			cin >> a >> b >> cc;
			c[a][b] += cc;
			line[a].push_back(b);
			line[b].push_back(a);
			linelist.push_back({ a,b });
		}

		nflow(1, n);
		
		for (auto a : linelist) {
			
			if (checkline(a.first, a.second))Ans++;
		}
	
	cout << Ans << endl;
	}


}