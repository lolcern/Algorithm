#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

struct shark {
	int size;
	int speed;
	int intel;
};

vector<int> line[103];
int a[104], b[54];
bool visited[103];

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

shark arr[53];


int main() {
	inp;
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		arr[i] = { u,v,w };

		for (int j = 1; j < i; j++) {
			//마시쪙
			if (arr[i].intel >= arr[j].intel && arr[i].size >= arr[j].size && arr[i].speed >= arr[j].speed) {
				line[i*2].push_back(j);
				line[i*2+1].push_back(j);
			}
			//먹힐때
			else if (arr[i].intel <= arr[j].intel && arr[i].size <= arr[j].size && arr[i].speed <= arr[j].speed) {
				line[j*2].push_back(i);
				line[j*2+1].push_back(i);
			}
		}
	}
	for (int i = 2; i <= n*2+1; i++) {
		if (!a[i]) {
			memset(visited, false, sizeof(visited));
			if (dfs(i))ans++;
		}
	}
	cout << n - ans << endl;
}