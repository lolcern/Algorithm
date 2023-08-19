#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int n, sqrtn;

struct Query {
	int s, e, n;
};

bool comp(Query a, Query b) {
	if (a.s / sqrtn == b.s / sqrtn) {
		return a.e < b.e;
	}
	return a.s < b.s;
}

ll a[100003];
ll cnt, numcnt[1000003], ans[100003];
vector<Query> q;
set<ll> st;

int main() {
	inp;
	int m;
	cin >> n >> m;
	sqrtn = sqrt(n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		q.push_back({ u,v,i });
	}
	sort(q.begin(), q.end(), comp);

	int s = q[0].s;
	int e = q[0].e;
	for (int i = s; i <= e; i++) {
		numcnt[a[i]]++;
		ans[q[0].n] += 1ll * (pow(numcnt[a[i]], 2) - pow(numcnt[a[i]] - 1, 2)) * a[i];
	}
	ll lst = ans[q[0].n];
	for (int i = 1; i < m; i++) {
		//업
		ans[q[i].n] = lst;
		while (q[i].s < s) { numcnt[a[--s]]++; ans[q[i].n] += 1ll * (pow(numcnt[a[s]], 2) - pow(numcnt[a[s]] - 1, 2)) * a[s]; }
		while (q[i].e > e) { numcnt[a[++e]]++; ans[q[i].n] += 1ll * (pow(numcnt[a[e]], 2) - pow(numcnt[a[e]] - 1, 2)) * a[e]; }
		while (q[i].s > s) { --numcnt[a[s++]]; ans[q[i].n] += 1ll * (pow(numcnt[a[s - 1]], 2) - pow(numcnt[a[s - 1]] + 1, 2)) * a[s-1]; }
		while (q[i].e < e) { --numcnt[a[e--]]; ans[q[i].n] += 1ll * (pow(numcnt[a[e + 1]], 2) - pow(numcnt[a[e + 1]] + 1, 2)) * a[e+1]; }
		//다운
		lst = ans[q[i].n];
	}

	for (int i = 0; i < m; i++) {
		cout << ans[i] << endl;
	}

}