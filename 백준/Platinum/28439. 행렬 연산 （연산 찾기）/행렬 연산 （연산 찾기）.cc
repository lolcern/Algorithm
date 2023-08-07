#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;



int main() {
	inp;

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n+1, (vector<int>(m+1, 0)));
	vector<int> h(n + 1);
	vector<int> y(m + 1);
	map<int, int> num;
	p M;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		num[v[1][1] - v[i][1]]++;
	}
	for (int i = 1; i <= m; i++) {
		num[v[1][i]]++;
	}
	for (auto a : num) {
		if (M.second < a.second) {
			M = a;
		}
	}

	for (int i = 1; i <= n; i++) {
		h[i] = M.first + v[i][1] - v[1][1];
	}
	for (int i = 1; i <= m; i++) {
		y[i] = v[1][i] - M.first;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (h[i] + y[j] != v[i][j]) {
				cout << "-1";
				exit(0);
			}
		}
	}

	cout << n + m - M.second << endl;
	for (int i = 1; i <= n; i++) {
		if (h[i]) {
			cout << "1 " << i << " " << h[i] << endl;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (y[i]) {
			cout << "2 " << i << " " << y[i] << endl;
		}
	}
}