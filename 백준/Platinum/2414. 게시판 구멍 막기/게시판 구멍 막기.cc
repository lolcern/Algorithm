#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

vector<int> line[3003];
char r[53][53];
int rr[53][53];
int a[3003], b[3003];
bool visited[3003];
int ans;

bool dfs(int x) {
	visited[x] = true;
	for (auto y : line[x]) {
		if (!b[y] || !visited[b[y]] && dfs(b[y])) {
			a[x] = y;
			b[y] = x;
			return true;
		}
	}
	return false;
}

int main() {
	inp;
	int n, m;
	int cnt = 0;
	int cnt2 = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> r[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		cnt++;
		for (int j = 1; j <= m; j++) {
			if (r[i][j] == '*') {
				rr[i][j] = cnt;
			}
			else if (r[i][j] == '.') {
				cnt++;
			}
		}
	}
	for (int j = 1; j <= m; j++) {
		cnt2++;
		for (int i = 1; i <= n;i++) {
			if (r[i][j] == '*') {
				line[rr[i][j]].push_back(cnt2);
			}
			else if (r[i][j] == '.') {
				cnt2++;
			}
		}
	}
	
	for (int i = 1; i <= cnt; i++) {
		if (!a[i]) {
			memset(visited, false, sizeof(visited));
			if (dfs(i))ans++;
		}
	}
	cout << ans;
}