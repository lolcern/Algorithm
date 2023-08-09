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
int a2[1003];
bool visited[1003];
int ans;
int ans2;

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
	int n, m,k;
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) {
			int  a, b;
			cin >> a;
			while (a--) {
				cin >> b;
				line[i].push_back(b);
			}
		}

		for (int i = 1; i <= n; i++) {
			if (!a[i]) {
				memset(visited, false, sizeof(visited));
				if (dfs(i))ans++;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!a2[i]) {
				memset(visited, false, sizeof(visited));
				if (dfs(i))ans2++;
				if (ans2 == k)break;
			}
		}
		cout << ans + ans2 << endl;
	
}