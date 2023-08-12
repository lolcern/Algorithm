#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef long long int ll;

struct line {
	ll a, b;
	line() : line(0, 0) {};
	line(ll A, ll B, double S = 0) :a(A), b(B) {}
};
double cont(line& a, line& b) {
	return (double)(b.b - a.b) / (a.a - b.a);
}

int n;
ll s[100003];
ll p[100003];
ll dp[100003];
vector<line> v(100003, line());
vector<vector<pair<int, ll>>> e(100003);
bool visited[100003];
int point = 1; //현재 dfs에서 삭제한 선의 위치 였던것

//어디가틀렸지어디가틀렸지어디가틀렸지

void dfs(int now, ll dis) {
	visited[now] = true;
	ll x = p[now];
	int wasidx = point; //복구할때

	int right = point - 1, left = 0;
	while (left < right) {
		int mid = (left + right+1) / 2;
		if (cont(v[mid],v[mid-1]) < x) {
			left = mid;
		}
		else {
			right = mid - 1;
		}
	}
	dp[now] = s[now] + v[left].b + x * (v[left].a + dis); //dp채우기

	line t(-dis,dp[now]);

	//직선 추가
	int l = 1, r = point;// l : 삭제할 선의 위치로 쓰일 예정
	while (l < r) { //넣을 곳 탐색
		int mid = (r + l) / 2;
		if (cont(t, v[mid - 1]) < cont(v[mid], v[mid - 1])) {
			r = mid;
		}
		else l = mid + 1;
	}
	line was = v[l]; //삭제한 선 저장
	v[l] = t;
	point = l + 1;
	
	//dfs
	for (auto a : e[now]) {
		if (!visited[a.first]) {
			dfs(a.first,dis + a.second);
		}
	}
	//roll back
	v[l] = was;
	point = wasidx;
}

int main() {
	inp;
	cin >> n;
	visited[1] = true;
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({ v,w });
		e[v].push_back({ u,w });
	}
	for (int i = 2; i <= n; i++) {
		cin >> s[i] >> p[i];
	}
	for (auto a : e[1]) {
		dfs(a.first,a.second);
	}
	for (int i = 2; i <= n; i++) {
		cout << dp[i] << " ";
	}
}