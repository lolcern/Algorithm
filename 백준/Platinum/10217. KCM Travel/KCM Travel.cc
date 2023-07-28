#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 9999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

struct air {
	ll dist; //dest인데;
	ll cost;
	ll time;
};

struct cmp {
	bool operator()(air a, air b) {
		return a.cost > b.cost;
	}
};

ll dp[103][10003]; //dp[i][j] = i까지 왔고 j 코스트를 쓸때 time의 최소값
vector<air> line[103];
priority_queue< air, vector< air>, cmp> pq;

int main() {
	inp;
	int t;
	ll ans = INF;
	cin >> t;
	ll n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = INF;
		}
	}
	for (int i = 0; i <= m; i++) {
		dp[1][i] = 0;
	}

	for (int i = 1; i <= k; i++) {
		ll u, v, c, d;
		cin >> u >> v >> c >> d;
		line[u].push_back({ v,c,d });
	}
	pq.push({ 1,0,0 });


	while (!pq.empty()) {
		air tmp = pq.top();
		pq.pop();

		if (ans <= dp[tmp.dist][tmp.cost]) {
			continue;
		}

		for (int i = 0; i < line[tmp.dist].size(); i++) {
			air a = line[tmp.dist][i];

			ll nxt = a.dist;
			ll sumcost = a.cost + tmp.cost;
			ll sumtime = dp[tmp.dist][tmp.cost] + a.time;
			if (sumcost > m) continue;
			if (ans <= sumtime)continue;
			if (nxt == n)
			{
				ans = sumtime;
				continue;
			}
			if (dp[nxt][sumcost] > sumtime) {
				if (dp[nxt][sumcost] == INF) {
					pq.push({ nxt,sumcost,sumtime });
				}
				dp[nxt][sumcost] = sumtime;
			}
		}
	}
	if (ans == INF) {
		cout << "Poor KCM";
	}
	else {
		cout << ans;
	}
}