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

void update(int x,int diff,int s = 1,int e = n,int node = 1){
	if (s > x || e < x) {
		return;
	}
	tree[node] += diff;
	if (s == e) {	
		return;
	}
	int mid = s + e >> 1;
	update(x, diff, s, mid, node * 2);
	update(x, diff, mid+1, e, node * 2 + 1);
}

int query(int x, int y, int s = 1, int e = n, int node = 1) {
	if (x > e || y < s) {
		return 0;
	}
	if (s >= x && e <= y) {
		return tree[node];
	}
	int mid = s + e >> 1;
	
	return query(x, y, s, mid, node * 2) + query(x, y, mid+1, e, node * 2+1);
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



	while (m--) {
		int a;
		cin >> a;

		if (a == 1) {
			int b, c;
			cin >> b >> c;
			update(num[b], c);
		}
		else {
			int b;
			cin >> b;
			cout << query(num[b], ed[num[b]]) << endl;
		}
	}
}