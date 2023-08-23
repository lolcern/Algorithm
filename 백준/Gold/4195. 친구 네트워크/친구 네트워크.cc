#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

map<string, int> m;
int parent[200005];
int friends[200005];

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		
		return parent[x] = find(parent[x]);
	}
}

bool Union(int x, int y) {
	if (x == y) {
		return false;
	}
	else {
		parent[x] = y;
		friends[y] += friends[x];
		return true;
	}
}

int main() {
	inp;

	int t;
	cin >> t;
	while (t--) {
		int n;
		int cnt = 0;
		cin >> n;
		for (int i = 1; i <= 2 * (n + 1); i++) {
			friends[i] = 1;
			parent[i] = i;
		}
		for (int i = 1; i <= n; i++) {
			string a,b;
			cin >> a >> b;
			if (m.find(a) == m.end()) {
				m.insert({ a,++cnt });
			}if (m.find(b) == m.end()) {
				m.insert({ b,++cnt });
			}
			int c = find(m[a]);
			int d = find(m[b]);
			Union(c, d);
			cout << friends[d] << endl;
		}
		m.clear();
	}

}