#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 210000000
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

vector<p> line[10003];
priority_queue<p, vector<p>, greater<>> pq;
bool visited[10003];
queue<int> q;
p cost[10003];
bool able[10003];
//0 : 맥, v+1 : 컾
int main() {
	inp;
	int  v, e;
	int x, y,m,s;
	cin >> v >> e;
	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		line[a].push_back({ b,c });
		line[b].push_back({ a,c });
	}
	cin >> m >> x;
	while (m--) {
		int a;
		cin >> a;
		able[a] = true;
		line[0].push_back({a,0});
	}
	cin >> s >> y;
	while (s--) {
		int a;
		cin >> a;
		able[a] = true;
		line[v + 1].push_back({ a,0 });
	}
	for (int i = 1; i <= v; i++) {
		cost[i] = { INF,INF };
	}
	pq.push({ 0,0 });
	while (!pq.empty()) {
		p now = pq.top();
		pq.pop();
		if (visited[now.second])continue;
		visited[now.second] = true;
		if (cost[now.second].first > x) {
			able[now.second] = true;
		}

		for (p a : line[now.second]) {
			if (!visited[a.first] && cost[a.first].first > now.first + a.second) {
				cost[a.first].first = now.first + a.second;
				pq.push({ cost[a.first].first, a.first });
			}
		}
	}
	memset(visited, false, sizeof(visited));
	pq.push({ 0,v+1 });
	while (!pq.empty()) {
		p now = pq.top();
		pq.pop();
		if (visited[now.second])continue;
		visited[now.second] = true;
		if (cost[now.second].second > y) {
			able[now.second] = true;
		}

		for (p a : line[now.second]) {
			if (!visited[a.first] && cost[a.first].second > now.first + a.second) {
				cost[a.first].second = now.first + a.second;
				pq.push({ cost[a.first].second, a.first });
			}
		}
	}
	p ans = { 0,INF };
	for (int i = 1; i <= v; i++) {
		if (!able[i]) {
			if (ans.second > cost[i].first + cost[i].second) {
				ans = { i,cost[i].first + cost[i].second };
			}
			
		}
	}
	if (ans.second == INF) {
		cout << "-1";
	}
	else {
		cout << ans.second;
	}
}