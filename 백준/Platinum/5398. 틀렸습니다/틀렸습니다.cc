#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;


int	num[2003][2003];
char grid[2003][2003];
vector<int> line[1003];
vector<int> tmp;
int a[1003], b[1003];
bool visited[1003];

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
		memset(num, 0, sizeof(num));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(grid, 0, sizeof(grid));
		for (int i = 1; i <= 500; i++) {
			line[i] = tmp;
		}
		int  n, m;
		int ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			int a, b;
			string c;
			cin >> a >> b >> c;
			for (int j = 0; j < c.size(); j++) {
				grid[b][a + j] = c[j];
				num[b][a + j] = i;
			}
		}
		for (int i = 1; i <= m; i++) {
			int a, b;
			string c;
			cin >> a >> b >> c;
			for (int j = 0; j < c.size(); j++) {
				if (grid[b + j][a] != c[j] && num[b+j][a] > 0) {
					line[num[b + j][a]].push_back(i);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!a[i]) {
				memset(visited, false, sizeof(visited));
				if (dfs(i))ans++;
			}
		}
		cout << n + m - ans << endl;

	}

}