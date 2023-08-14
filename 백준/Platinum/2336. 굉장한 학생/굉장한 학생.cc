#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

struct stu {
	int first, second, third;
};

bool comp(stu a,stu b){
	return a.first < b.first;
}

int n;
vector<stu> s;
int tree[2000003];

int update(int x, int y, int s = 1, int e = n, int node = 1) {//x자리y넣기
	if (x >= s && x <= e) {
		if (s == e) {
			return tree[node] = y;
		}
		int mid = s + e >> 1;
		return tree[node] = min(update(x, y, s, mid, node * 2), update(x, y, mid + 1, e, node * 2 + 1));
	}
	return tree[node];
}

bool check(int x, int y,int s = 1, int e = n, int node = 1) { //x이상 인덱스에 <y가 존재하는가
	if (s > x) return false;
	if (e <= x) {
		return tree[node] < y;
		
	}
	else {
		int mid = s + e >> 1;
		return check(x, y, s, mid, node * 2) || check(x, y, mid + 1, e, node * 2 + 1);
	}
}

int main() {
	inp;
	cin >> n;
	s.resize(n+1);
	memset(tree, 999999, sizeof(tree));

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		s[a].first = i;
	}
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		s[a].second = i;
	}
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		s[a].third = i;
	}
	sort(s.begin(), s.end(), comp);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		update(s[i].second, s[i].third);
		if (!check(s[i].second, s[i].third)) {
			ans++;
		}
	}
	cout << ans;
}