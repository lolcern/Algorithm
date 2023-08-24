#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int visited[103];
vector<int> line[103];
int a[103], b[103];
int n;
int m;

bool dfs(int x) {
	visited[x] = true;
	for (auto y : line[x]) {
		if (b[y] == 0 || !visited[b[y]] && dfs(b[y])) {
			a[x] = y;
			b[y] = x;
			return true;
		}
	}
	return false;
}

int main() {
	inp;
	int t;
	
	cin >> t;
	while (t--) {
		fill(a, a + 103, 0);
		fill(b, b + 103, 0);
		for (int i = 1; i <= 100; i++) {
			line[i].clear();
		}
		cin >> n >> m;
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			int t1, t2, nm;
			cin >> t1 >> t2 >> nm;
			while (nm--) {
				int r;
				cin >> r;
				for (int j = t1 + 1; j <= t2; j++) {
					line[j].push_back(r);
				}
			}
		}

		for (int i = 1; i <= 100; i++) {
			if (!a[i]) {
				memset(visited, false, sizeof(visited));
				if (dfs(i))ans++;
				if (ans == n) {
					cout << i << endl;
					break;
				}
			}
		}

		if (ans != n) {
			cout << "-1" << endl;
		}

	}

	
}