#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

ll grass[103][103];
int dx[20] = {0,1,-1,0,0,3,2,2,1,1,0,0,-1,-1,-2,-2,-3};
int dy[20] = {0,0,0,1,-1,0,1,-1,2,-2,3,-3,2,-2,1,-1,0};
bool visited[103][103];
ll cost[103][103];
priority_queue<pair<ll, p>, vector<pair<ll, p>>, greater<>>pq; //pq.first = 비용, pq.second = 위치


int main() {
	inp;
	ll n, t;
	cin >> n >> t;
	cost[n][n] = 40000000000;
	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++){
			cin >> grass[i][j];
		}
	}

	pq.push({ 0,{1,1} });

	while (!pq.empty()) {
		pair<int, p> tmp = pq.top();
		pq.pop();
		if (visited[tmp.second.first][tmp.second.second]) {
			continue;
		}
		else {
			visited[tmp.second.first][tmp.second.second] = true;
			cost[tmp.second.first][tmp.second.second] = tmp.first;
		}

		for (int i = 1; i <= 16; i++) {
			int x = tmp.second.first + dx[i];
			int y = tmp.second.second + dy[i];

			if (x >= 1 && x <= n && y >= 1 && y <= n) {
				if (!visited[x][y]) {
					pq.push({ tmp.first + grass[x][y] + t * 3,{x,y} });
				}
			}
		}
	}

	cost[n][n] = min(min(cost[n][n - 1], cost[n - 1][n]) + t,cost[n][n]);
	cost[n][n] = min(min(cost[n][n], 2 * t + cost[n][n - 2]), min(2 * t + cost[n - 1][n - 1], 2 * t + cost[n - 2][n]));

	cout << cost[n][n];


}