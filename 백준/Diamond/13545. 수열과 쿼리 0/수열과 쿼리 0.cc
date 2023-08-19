#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int n, k;
int sqrtn;

struct Query {
	int s, e, n;
};

bool comp(Query a, Query b) {
	if (a.s / sqrtn == b.s / sqrtn) {
		return a.e < b.e;
	}
	return a.s < b.s;
}

int a[101003];
int aa[101003];
int cnt[101003];
int ans[101003];
int res;
list<int> d[201003];
vector<Query> q;
int group[400];

void pl(int idx, bool front) {
	int now;
	if (!d[a[idx]].empty()) {
		now = d[a[idx]].back() - d[a[idx]].front();
		cnt[now]--;
		group[now / sqrtn]--;
	}
	if (front)d[a[idx]].push_front(idx);
	else d[a[idx]].push_back(idx);
	now = d[a[idx]].back() - d[a[idx]].front();
	cnt[now]++;
	group[now / sqrtn]++;
}

void mi(int idx, bool front) {
	int now;
	now = d[a[idx]].back() - d[a[idx]].front();
	cnt[now]--;
	group[now / sqrtn]--;
	if (front)d[a[idx]].pop_front();
	else d[a[idx]].pop_back();
	if (!d[a[idx]].empty()) {
		now = d[a[idx]].back() - d[a[idx]].front();
		cnt[now]++;
		group[now / sqrtn]++;
	}
}

int find() {
	for (int i = sqrtn + 10; i >= 0; i--) {
		if (group[i]) {
			for (int j = sqrtn - 1; j >= 0; j--) {
				if (cnt[i * sqrtn + j]) {
					return i * sqrtn + j;
				}
			}
		}
	}
	return 0;
}

int main() {
	inp;
	cin >> n;
	sqrtn = sqrt(n);
	a[0] = 100000;
	for (int i = 1; i <= n; i++) {
		cin >> aa[i];
		a[i] = a[i-1] + aa[i];
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		q.push_back({ u-1,v,i });
	}
	sort(q.begin(), q.end(), comp);
	int s = q[0].s;
	int e = q[0].e;

	for (int i = s; i <= e; i++) {
		pl(i, false);
	}
	ans[q[0].n] = find();

	for (int i = 1; i < m; i++) {
		while (q[i].s < s)pl(--s, true);
		while (q[i].e > e)pl(++e, false);
		while (q[i].s > s)mi(s++, true);
		while (q[i].e < e)mi(e--, false);
		ans[q[i].n] = find();
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << endl;
	}
}