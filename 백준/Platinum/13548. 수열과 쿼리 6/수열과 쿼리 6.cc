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
int cnt, numcnt[100003], ans[100003];
int cntt[100003];
int mx;
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
		cntt[numcnt[a[i]]]--;
		numcnt[a[i]]++;
		cntt[numcnt[a[i]]]++;
		mx = max(mx, numcnt[a[i]]);
		
	}
	ans[q[0].n] = mx;

	for (int i = 1; i < m; i++) {
		//업
		while (q[i].s < s) { cntt[numcnt[a[--s]]]--; numcnt[a[s]]++; cntt[numcnt[a[s]]]++; mx = max(mx, numcnt[a[s]]); }
		while (q[i].e > e) { cntt[numcnt[a[++e]]]--; numcnt[a[e]]++; cntt[numcnt[a[e]]]++; mx = max(mx, numcnt[a[e]]); }
		while (q[i].s > s) {
			if (mx == numcnt[a[s]] && cntt[numcnt[a[s]]] == 1) {
				mx--;
			}
			cntt[numcnt[a[s]]]--; 
			numcnt[a[s]]--; 
			cntt[numcnt[a[s]]]++;
			s++;
		}
		while (q[i].e < e) {
			if (mx == numcnt[a[e]] && cntt[numcnt[a[e]]] == 1) {
				mx--;
			}
			cntt[numcnt[a[e]]]--;
			numcnt[a[e]]--; 
			cntt[numcnt[a[e]]]++;
			e--;
		}
		ans[q[i].n] = mx;
		//다운
	}

	for (int i = 0; i < m; i++) {
		cout << ans[i] << endl;
	}

}