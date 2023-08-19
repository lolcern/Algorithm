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

int a[100003];
int cnt, numcnt[1000003], ans[100003];
vector<Query> q;

int main() {
	inp;
	cin >> n;
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
		if (!numcnt[a[i]]) cnt++;
		numcnt[a[i]]++;
	}
	ans[q[0].n] = cnt;

	for (int i = 1; i < m; i++) {
		//업
		while (q[i].s < s) if (numcnt[a[--s]]++ == 0) cnt++;
		while (q[i].e > e)if (numcnt[a[++e]]++ == 0)cnt++;
		while (q[i].s > s)if (--numcnt[a[s++]] == 0)cnt--;
		while (q[i].e < e)if (--numcnt[a[e--]] == 0)cnt--;
		ans[q[i].n] = cnt;
		//다운
	}

	for (int i = 0; i < m; i++) {
		cout << ans[i] << endl;
	}

}