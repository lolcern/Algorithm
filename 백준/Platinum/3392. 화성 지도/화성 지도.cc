#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

struct coord {
	int x, y1,y2;
	bool pl;
};

bool comp(coord a, coord b) {
	return a.x < b.x;
}

ll tree[120003]; //특정 구간을 지나는 네모개수
ll num[120003]; //넘
vector<coord> sq;
	int n;
	ll ans;

void update(int x,int y,int diff,int s = 1,int e = 30000, int node = 1) {
	if (s > y || e < x)return;
	if (x <= s && y >= e) {
		tree[node] += diff;
	}
	else {
		int mid = s + e >> 1;
		update(x, y, diff, s, mid, node * 2);
		update(x, y, diff, mid+1, e, node * 2+1);
	}
	if (tree[node]) num[node] = e - s + 1;
	else {
		if (s == e)num[node] = 0;
		else num[node] = num[node * 2] + num[node * 2 + 1];
	}
}

int main() {
	inp;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		sq.push_back({ x1,y1,y2,true });
		sq.push_back({ x2,y1,y2,false });
	}
	sort(sq.begin(), sq.end(), comp);

	int lst = 0;

	for (auto a : sq) {
		if (a.x != lst) {
			ans += num[1] * (a.x - lst);
			lst = a.x;
		}
		update(a.y1, a.y2 - 1, a.pl ? 1 : -1);
	}
	cout << ans;
}