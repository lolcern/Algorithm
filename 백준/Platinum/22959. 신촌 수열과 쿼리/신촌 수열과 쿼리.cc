#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

struct seg {
	ll m;
	ll s;
};

seg comb(seg a,seg b) {
	return { min(a.m,b.m), a.s + b.s };
}


int n;
seg tree[800001];
ll a[200001];

seg init(int s = 1, int e = n, int node = 1) {
	if (s == e)return tree[node] = { a[s],a[s] };
	int mid = s + e >> 1;
	return tree[node] = comb(init(s, mid, node * 2), init(mid + 1, e, node * 2 + 1));
}

seg update(int x, ll diff, int s = 1, int e = n, int node = 1) {
	if (s > x || e < x) return tree[node];
	if (s == e)return tree[node] = { diff,diff };
	int mid = s + e >> 1;
	return tree[node] = comb(update(x, diff, s, mid, node * 2), update(x, diff, mid+1, e, node * 2 + 1));
}

ll minquery(int x, int y, int s = 1, int e = n, int node = 1) {
	if (s > y || e < x) {
		return MOD;
	}
	if (s >= x && e <= y) return tree[node].m;
	int mid = s + e >> 1;
	return min(minquery(x, y, s, mid, node * 2), minquery(x, y, mid + 1, e, node * 2 + 1));
}

ll sumquery(int x, int y, int s = 1, int e = n, int node = 1) {
	if (s > y || e < x) {
		return 0;
	}
	if (s >= x && e <= y) return tree[node].s;
	int mid = s + e >> 1;
	return sumquery(x, y, s, mid, node * 2) + sumquery(x, y, mid + 1, e, node * 2 + 1);
}

int main() {
	inp;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	init();
	int m;
	cin >> m;
	while (m--) {
		int b, c, d;
		cin >> b >> c >> d;
		if (b == 1) {
			update(c, d);
		}
		else {
			//c 기준 오른쪽에서 찾기
			int l = c, r = n;
			int right = c;
			while (l <= r) {
				int md = l + r >> 1;
				if (minquery(l, md) >= d) {
					right = md;
					l = md + 1;
				}
				else {
					r = md - 1;
				}
			}
			//c 기준 왼쪽으로 찾기
			l = 1, r = c;
			int left = c;
			while (l <= r) {
				int md = l + r >> 1;
				if (minquery(md, r) >= d) {
					left = md;
					r = md - 1;
				}
				else {
					l = md + 1;
				}
			}
			cout << sumquery(left, right) << endl;
		}
	}
	
}