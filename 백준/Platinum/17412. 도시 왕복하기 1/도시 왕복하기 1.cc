#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int c[403][403];
int f[403][403];
int pre[403];
vector<int> line[403];
queue<int> q;
int ans;

int main() {
	inp;
	int n, p;
	cin >> n >> p;
	while (p--) {
		int a, b;
		cin >> a >> b;
		c[a][b] = 1;
		line[a].push_back(b);
		line[b].push_back(a);
	}

	while (1) {
		memset(pre, 0, sizeof(pre));
		q = queue<int>();
		q.push(1);
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
		for (int i = 2; i != 1; i = pre[i]) {
			f[pre[i]][i]++;
			f[i][pre[i]]--;
		}
		ans++;
	}
	cout << ans;
}