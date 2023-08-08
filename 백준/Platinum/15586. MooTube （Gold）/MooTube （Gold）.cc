#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef tuple<int, int, int> t;
typedef pair<int, int> pi;
typedef long long int ll;

struct compare {
	bool operator()(t &a, t &b) {
		return get<2>(a) < get<2>(b);
	}
};

int par[100003];
int cnt[100003];
int ans[100003];
priority_queue<t, vector<t>, compare>  pq;
priority_queue<t, vector<t>, compare> pq2;

int find(int x) {
	if (x == par[x])return x;
	return par[x] = find(par[x]);
}

bool uni(int x,int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	par[x] = y;
	cnt[y] += cnt[x];
	return true;
}

void qu(int x) {
	while (!pq2.empty()) {
		t now = pq2.top();
		if (get<2>(now) < x) break;
		pq2.pop();
		ans[get<0>(now)] = cnt[find(get<1>(now))] - 1;
	}
}



int main() {
	inp;
	for (int i = 1; i <= 100000; i++) {
		par[i] = i;
		cnt[i] = 1;
	}
	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u, v, r;
		cin >> u >> v >> r;
		pq.push({ u,v,r });
	}
	for (int i = 1; i <= q; i++)
	{
		int v, k;
		cin >> k >> v;
		pq2.push({ i,v,k });
	}
	int now = 2000000000;
	while (!pq.empty()) {
		t f = pq.top();
		if (get<2>(f) != now) {
			now = get<2>(f);
			qu(get<2>(f) + 1);
		}
		pq.pop();
		uni(get<0>(f), get<1>(f));
	}
	qu(1);
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << endl;
	}
}