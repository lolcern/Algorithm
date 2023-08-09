#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

vector<int> line[5003];
int a[5003], b[5003];
bool visited[5003];
char chess[103][103];
int arr[103][103];
int arr2[103][103];

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
	int n;
	int num = 1;
	int num2 = 1;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> chess[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (chess[i][j] == '.') {
				arr[i][j] = num;
				if (j == n || chess[i][j + 1] == 'X') {
					num++;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (chess[j][i] == '.') {
				arr2[j][i] = num2;
				if (j == n || chess[j + 1][i] == 'X')num2++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (chess[i][j] == '.')line[arr[i][j]].push_back(arr2[i][j]);
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= num; i++) {
			memset(visited, false, sizeof(visited));
			if (dfs(i))ans++;
	}
	cout << ans;

}