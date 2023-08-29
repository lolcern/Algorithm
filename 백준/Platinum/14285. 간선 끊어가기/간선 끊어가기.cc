#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

priority_queue<p, vector<p>, greater<>> pq;
vector<p> edge;
vector<p> line[5003];
int sdis[5003];//s에서i로
int edis[5003];//e에서i로
int s, e;
int sum = 0;


int main() {
	inp;
	int n, m;
	cin >> n >> m;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ a,b });
		line[a].push_back({ b,c });
		line[b].push_back({ a,c });
		sum += c;
	}

	cin >> s >> e;

	//s에서 시작하는 다익스트라
	fill(sdis, sdis + 5003, INF);
	pq.push({ 0,s });
	sdis[s] = 0;
	while (!pq.empty()) {
		p now = pq.top();
		pq.pop();
		if (sdis[now.second] < now.first) continue;
		sdis[now.second] = now.first;
		for (auto a : line[now.second]) {
			if (sdis[a.first] == INF)pq.push({ now.first + a.second, a.first });
		}
	}
	//e에서 시작하는 다익스트라
	fill(edis, edis + 5003, INF);
	pq.push({ 0,e });
	edis[e] = 0;
	while (!pq.empty()) {
		p now = pq.top();
		pq.pop();
		if (edis[now.second] < now.first) continue;
		edis[now.second] = now.first;
		for (auto a : line[now.second]) {
			if (edis[a.first] == INF)pq.push({ now.first + a.second, a.first });
		}
	}

	//간선별로 비교해보기

	int minus = INF;

	for (auto a : edge) {
		minus = min(minus, sdis[a.first] + edis[a.second]);
		minus = min(minus, edis[a.first] + sdis[a.second]);
	}
	cout << sum - minus;
}