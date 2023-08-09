#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> p;

map<ll, int> m;
vector<int> line[2503];
int a[2503], b[10003];
bool visited[2503];
p l[2503];

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
	int ans = 0;
	cin >> n;
	int num = 0;
	for (int i = 1; i <= n; i++) {
		ll a, b;
		cin >> a >> b;
		l[i] = { a,b };
		if (m.find(a + b) == m.end()) {
			m.insert({ a + b, ++num });
			line[i].push_back(num);
		}
		else {
			line[i].push_back(m.find(a + b)->second);
		}
		if (m.find(a - b) == m.end()) {
			m.insert({ a - b, ++num });
			line[i].push_back(num);
		}
		else {
			line[i].push_back(m.find(a - b)->second);
		}
		if (m.find(a * b) == m.end()) {
			m.insert({ a * b, ++num });
			line[i].push_back(num);
		}
		else {
			line[i].push_back(m.find(a * b)->second);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!a[i]) {
			memset(visited, false, sizeof(visited));
			if (dfs(i))ans++;
		}
	}
	if (ans != n) { cout << "impossible" << endl; exit(0); }


	for (int i = 1; i <= n; i++)
	{
		if (m.find(l[i].first + l[i].second)->second == a[i]) {
			cout << l[i].first << " + " << l[i].second << " = " << l[i].first + l[i].second << endl;
		}
		else if (m.find(l[i].first - l[i].second)->second == a[i]) {
			cout << l[i].first << " - " << l[i].second << " = " << l[i].first - l[i].second << endl;
		}
		else if (m.find(l[i].first * l[i].second)->second == a[i]) {
			cout << l[i].first << " * " << l[i].second << " = " << l[i].first * l[i].second << endl;
		}
	}
}