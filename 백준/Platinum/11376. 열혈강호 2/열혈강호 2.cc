#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

vector<int> line[2003];
vector<int> tmp;
int a[2003], b[2003];
bool visited[2003];
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
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			int  a, b;
			cin >> a;
			while (a--) {
				cin >> b;
				line[i*2].push_back(b);
				line[i * 2 + 1].push_back(b);
			}
		}

		for (int i = 2; i <= n*2+1; i++) {
			if (!a[i]) {
				memset(visited, false, sizeof(visited));
				if (dfs(i))ans++;
			}
		}
		cout << ans << endl;
	
}