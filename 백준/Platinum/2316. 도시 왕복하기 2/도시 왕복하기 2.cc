#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int c[801][801], f[801][801];
vector<int> line[801];
int ans;
int pre[801];

int main() {
	inp;
	int n,p;
	cin >> n >> p;
	for (int i = 3; i <= n; i++) {
		c[i][i + 400] = 1;
		line[i].push_back(i + 400);
		line[i + 400].push_back(i);
	}
	for (int i = 1; i <= p; i++) {
		int a, b;
		cin >> a >> b;
		c[a+400][b] = 9999;
		c[b+400][a] = 9999;
		line[a+400].push_back(b);
		line[b+400].push_back(a);
		line[b].push_back(a + 400);
		line[a].push_back(b + 400);

	}

	while (1) {
		memset(pre, 0, sizeof(pre));
		queue<int> q;
		q.push(401);
		while (!q.empty() && pre[2] == 0) {
			int now = q.front();
			q.pop();
			for (auto nxt : line[now]) {
				if (c[now][nxt] > f[now][nxt] && pre[nxt] == 0) {
					q.push(nxt);
					pre[nxt] = now;
					if (nxt == 2)break;
				}
			}
		}
		if (pre[2] == 0)break;

		for (int i = 2; i != 401; i = pre[i]) {
			f[pre[i]][i]++;
			f[i][pre[i]]--;
		}
		ans++;
	}

	cout << ans;

}