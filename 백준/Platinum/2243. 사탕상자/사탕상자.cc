#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int tree[4000003];

void update(int x, int num, int st = 1, int ed = 1000000, int node = 1) {
	if (st <= x && ed >= x) {
		tree[node] += num;
		if (st == ed) {
			return;
		}
	}
	else {
		return;
	}
	int mid = (st + ed) / 2;
	update(x, num, st, mid, node * 2);
	update(x, num, mid + 1, ed, node * 2 + 1);
}

int query(int x) {
	int st = 1;
	int ed = 1000000;
	int node = 1;
	while (st != ed) {
		if (tree[node*2] < x) {
			x -= tree[node*2];
			node = node * 2 + 1;
			st = (st+ed)/2 + 1;
		}
		else {
			node = node * 2;
			ed = (st + ed) / 2;
		}
	}
	return st;
}


int main() {
	inp;
	int n;
	cin >> n;
	while (n--) {
		int  a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b;
			c = query(b);
			cout << c << endl;
			update(c, -1);
		}
		else {
			cin >> b >> c;
			update(b, c);
		}
	}
}