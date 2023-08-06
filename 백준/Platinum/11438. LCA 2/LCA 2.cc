#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int par[100003][20];
int d[100003];
vector<int> line[100003];

void dfs(int now) {
	for (auto a : line[now]) {
		if (d[a] == 0) {
			par[a][0] = now;
			d[a] = d[now] + 1;
			dfs(a);
		}
	}
}

int main() {
	inp;
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		line[a].push_back(b);
		line[b].push_back(a);
	}
	d[1] = 1;
	memset(par, -1, sizeof(par));
	dfs(1);

	for (int i = 0; i < 17; i++) {
		for (int j = 2; j <= n; j++) {
			if (par[j][i] != -1) {
				par[j][i + 1] = par[par[j][i]][i];
			}
		}
	}


	int m;
	cin >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;

		if (d[a] < d[b]) swap(a, b);

		int diff = d[a] - d[b];

		for (int i = 0; diff; i++) {
			if (diff & 1 << i) a = par[a][i];
			diff &= ~(1 << i);
		}

		if (a != b) {
			for (int i = 17; i >= 0; i--) {
				if (par[a][i] != -1 && par[a][i] != par[b][i]) {
					a = par[a][i];
					b = par[b][i];
				}
			}
		a = par[a][0];
		}
		cout << a << endl;
	}
}