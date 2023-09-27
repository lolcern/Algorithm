#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

bool visited[2003];
int a[2003],b[2003];
vector<int> line[2003];
bool sf[2003];

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

int main(){
	inp;
	int n,m;
	cin >> n >> m;
	
	for(int i = 1; i <= n;i++){
		int u;char v;
		cin >> u >> v;
		if(v == 's'){
			sf[u] = true;
		}
	}
	for(int i = 1; i <= m; i++){
		int u,v;
		cin >> u >> v;
		if(sf[u]){
			line[u].push_back(v);
			
		}
		else line[v].push_back(u);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!a[i] && sf[i]) {
			memset(visited, false, sizeof(visited));
			if (dfs(i))ans++;
		}
	}

	cout << n - ans;
}