#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

vector<int> line[503];
vector<int> tmp;
int a[503], b[503];
bool visited[1003];
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
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int  a, b;
		cin >> a >> b;
		line[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (!a[i]) {
			memset(visited, false, sizeof(visited));
			if (dfs(i))ans++;
		}
	}
	cout << ans << endl;

}