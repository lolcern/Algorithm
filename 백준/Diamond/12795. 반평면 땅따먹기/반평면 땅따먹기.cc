#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

struct Line {
	ll a, b;
	ll get(ll x) {
		return a * x + b;
	}
};

struct Node {
	int l, r;
	ll s, e;
	Line line;
};

vector<Node> tree;

void init(ll s, ll e) {
	tree.push_back({ -1,-1,s,e,{0,LLONG_MIN} });
}

void update(int node, Line t) {
	ll s = tree[node].s;
	ll e = tree[node].e;
	ll m = s + e >> 1;

	Line low = tree[node].line;
	Line high = t;
	if (low.get(s) > high.get(s)) swap(low, high); //s를 기준으로 low high 정하기
	if (low.get(e) <= high.get(e)) { //e를  기준으로 low high 뭐 뭐 하기
		tree[node].line = high;
		return;
	}
	
	if (low.get(m) < high.get(m)) { //교점이 오른쪽에 있을때
		tree[node].line = high;
		if (tree[node].r == -1) {
			tree[node].r = tree.size();
			tree.push_back({ -1,-1,m + 1,e,{0,LLONG_MIN} });
		}
		update(tree[node].r, low);
	}
	else {//교점이 왼쪽에 있을때
		tree[node].line = low;
		if (tree[node].l == -1) {
			tree[node].l = tree.size();
			tree.push_back({ -1,-1,s,m,{0,LLONG_MIN} });
		}
		update(tree[node].l, high);
	}
}

ll query(int node, ll x){
	if (node == -1) return LLONG_MIN;
	ll s = tree[node].s, e = tree[node].e;
	ll m = s + e >> 1;
	if (x <= m)return max(tree[node].line.get(x), query(tree[node].l, x));
	else return max(tree[node].line.get(x), query(tree[node].r, x));
}
int main() {
	inp;
	init(-1000000000000, 1000000000000);
	int q;
	cin >> q;
	while (q--) {
		ll a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			update(0,{ b,c });
		}
		else {
			cin >> b;
			cout << query(0, b) << endl;
		}
	}
}