#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int n, m;
vector<int> line[100003];
int num[100003];
int ed[100003];
int cnt = 0;
bool visited[100003];
int tree2[400003];
int tree[400003];
int lazy[400003];

void dfs(int now = 1) {
	visited[now] = true;
	num[now] = ++cnt;
	for (auto a : line[now]) {
		if (!visited[a]) {
			dfs(a);
		}
	}
	ed[num[now]] = cnt;
}


//segment tree

void update2(int x,int diff,int s = 1,int e = n,int node = 1){
	if (s > x || e < x) {
		return;
	}
	tree2[node] += diff;
	if (s == e) {	
		return;
	}
	int mid = s + e >> 1;
	update2(x, diff, s, mid, node * 2);
	update2(x, diff, mid+1, e, node * 2 + 1);
}

int query2(int x, int y, int s = 1, int e = n, int node = 1) {
	if (x > e || y < s) {
		return 0;
	}
	if (s >= x && e <= y) {
		return tree2[node];
	}
	int mid = s + e >> 1;
	
	return query2(x, y, s, mid, node * 2) + query2(x, y, mid+1, e, node * 2+1);
}

void propagate(int s, int e, int node) {
	if (lazy[node]) {
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		tree[node] += (e - s + 1) * lazy[node];
		lazy[node] = 0;
	}
}

void update(int x, int y, int diff, int s = 1, int e = n, int node = 1) {
	propagate(s, e, node);
	if (x > e || y < s) return;
	if (s >= x && e <= y) {
		lazy[node] += diff;
		propagate(s, e, node);
		return;
	}
	int mid = s + e >> 1;
	update(x, y, diff, s, mid, node * 2);
	update(x, y, diff, mid + 1, e, node * 2 + 1);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int x, int s = 1, int e = n, int node = 1) {
	propagate(s, e, node);
	if (s > x || e < x) return 0;
	if (s == e && e == x) {
		return tree[node];
	}

	int mid = s + e >> 1;
	return query(x, s, mid, node * 2) + query(x, mid + 1, e, node * 2 + 1);

}

int main() {
	inp;
	cin >> n >> m;
	int dummy;
	cin >> dummy;
	for (int i = 2; i <= n; i++) {
		int a;
		cin >> a;
		line[a].push_back(i);
	}

	//dfs
	dfs();

	bool tst = false;

	while (m--) {
		int a;
		cin >> a;

		if (a == 1) {
			int b, c;
			cin >> b >> c;
			if (!tst) {
				update(num[b], ed[num[b]], c);
			}
			else
			update2(num[b], c);
		}
		else if(a==2){
			int b;
			cin >> b;
			cout << query2(num[b], ed[num[b]]) + query(num[b]) << endl;
		}
		else {
			tst ^= true;
		}
	}
}