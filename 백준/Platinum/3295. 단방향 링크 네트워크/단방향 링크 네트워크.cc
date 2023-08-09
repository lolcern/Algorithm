#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

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
		int n,m;
		int ans = 0;
		for (int i = 1; i <= 1000; i++) {
			line[i] = tmp;
		}
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		cin >> n >> m;
		while (m--) {
			int a, b;
			cin >> a >> b;
			line[a + 1].push_back(b + 1);
		}

		for (int i = 1; i <= n; i++) {
			if (!a[i]) {
			memset(visited, false, sizeof(visited));
			if (dfs(i))ans++;

			}
		}
		cout << ans << endl;
	}

}