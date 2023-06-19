#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
#define N 100000
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

struct seg {
	ll lmax;
	ll rmax;
	ll max;
	ll sum;
};

seg tree[N * 4];
ll arr[100003];
ll n;

seg bb(seg a, seg b) {
	if (b.max == -INF) {
		return a;
	}
	else if (a.max == -INF) {
		return b;
	}
	seg ret;
	ret.lmax = max(a.lmax, a.sum + b.lmax);
	ret.rmax = max(b.rmax, a.rmax + b.sum);
	ret.max = max(max(a.max, b.max), a.rmax + b.lmax);
	ret.sum = a.sum + b.sum;
	return ret;
}

seg init(int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node].lmax = arr[start];
		tree[node].rmax = arr[start];
		tree[node].max = arr[start];
		tree[node].sum = arr[start];
		return tree[node];
	}
	int mid = (start + end) / 2;

	return tree[node] = bb(init(node << 1, start, mid),init(node << 1 | 1, mid + 1, end));
}

seg query(int left, int right, int node = 1, int start = 1, int end = n) {
	if (left > end || right < start) {
		return { -INF,-INF,-INF,-INF };
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return bb(query(left, right, node << 1, start, mid), query(left, right, node << 1 | 1, mid + 1, end));
}


int main() {
	inp;

	cin >> n;
	

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init();
	seg rr = query(1, 1);
	int m;
	cin >> m;
	while (m--) {
		int x1, y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll ans = 0;
		if (y1 > x2) {
			//복잡스
			seg i = query(x1, x2);
			seg j = query(x2, y1);
			seg k = query(y1, y2);
			ans = i.rmax + j.sum + k.lmax - arr[x2] - arr[y1];
			ans = max(ans, i.rmax + j.lmax - arr[x2]);
			ans = max(ans, j.rmax + k.lmax - arr[y1]);
			ans = max(ans, j.max);
			cout << ans << endl;
		}
		else {
			ans += query(x1, y1).rmax;
			ans += query(x2, y2).lmax;
			ans += query(y1, x2).sum;
			ans -= arr[y1];
			ans -= arr[x2];
			cout << ans << endl;
		}
		//cout << query(x, y).max << endl;
	}
}