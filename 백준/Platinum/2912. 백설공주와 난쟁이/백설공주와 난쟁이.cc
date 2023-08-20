#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int n, sqrtn,c;

struct Query {
	int s, e, n;
};

bool comp(Query a, Query b) {
	if (a.s / sqrtn == b.s / sqrtn) {
		return a.e < b.e;
	}
	return a.s < b.s;
}

int a[300003];
int colorcnt[10003];
int ans[10003];
vector<Query> q;


int main() {
	inp;
	cin >> n >> c;
	sqrtn = sqrt(n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		q.push_back({ u,v,i });
	}
	sort(q.begin(), q.end(), comp);

	int s = q[0].s;
	int e = q[0].e;
	for (int i = s; i <= e; i++) {
		colorcnt[a[i]]++;
	}
	for (int i = 1; i <= c; i++) {
		if (colorcnt[i] > (e - s + 1) / 2) {
			ans[q[0].n] = i;
			break;
		}
	}

	for (int i = 1; i < m; i++) {
		while (q[i].s < s) { colorcnt[a[--s]]++; }
		while (q[i].e > e) { colorcnt[a[++e]]++; }
		while (q[i].s > s) { colorcnt[a[s++]]--; }
		while (q[i].e < e) { colorcnt[a[e--]]--; }

		for (int j = 1; j <= c; j++) {
			if (colorcnt[j] > (q[i].e - q[i].s + 1) / 2) {
				ans[q[i].n] = j;
				break;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		if (ans[i]) {
			cout << "yes" << " " << ans[i] << endl;
		}
		else {
			cout << "no" << endl;
		}
	}

}