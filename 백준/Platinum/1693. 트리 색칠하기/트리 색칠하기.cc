#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int dp[100003][11]; //dp[i][j] : i번 + i의 서브트리까지 j 색으로 칠할때 비용최소값
int n;

vector<int> line[100003];

void dfs(int now,int par) {
	for (auto a : line[now]) {
		if (a != par) {
			dfs(a, now);
		}
	}

	for (int i = 1; i <= min(10, n); i++) {
		dp[now][i] = i;
		for (auto a : line[now]) {
			int mm = INF;
			for (int j = 1; j <= min(10, n); j++) {
				if (i != j) {
					mm = min(mm, dp[a][j]);
				}
			}
			dp[now][i] += mm;
		}
	}

}

int main() {
	inp;
	cin >> n;

	for (int i = 1; i <= n - 1; i++) {
		int a, b;
		cin >> a >> b;
		line[a].push_back(b);
		line[b].push_back(a);
	}

	dfs(1, 0);
	int mm = INF;
	for (int i = 1; i <= min(n, 10); i++) {
		mm = min(mm, dp[1][i]);
	}
	cout << mm;
}