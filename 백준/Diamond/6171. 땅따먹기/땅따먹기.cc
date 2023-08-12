#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

struct line {
	ll a, b;
	double s;

	line(ll A, ll B, double S = 0) :a(A), b(B), s(S) {}
};

//교점의 x좌표 구하기
double cont(line &a, line &b){
	return (double)(b.b - a.b) / (a.a - b.a);
}

struct ground {
	ll w;
	ll h;
};

struct compare {
	bool operator()(ground a, ground b) {
		if (a.w == b.w) {
			return a.h > b.h;
		}
		return a.w > b.w;
	}
};

/*
* w에 대해 오름차순으로 정렬
* 하나하나 우선순위 큐에서 빼면서 나와있는 원소들 중 본인보다 h가 작거나 같은 원소 삭제
* w를 기준으로 cht 실행
*/

int n;
vector<line> v;
ll dp[50003];
vector<ground> g;
priority_queue<ground, vector<ground>, compare> pq;


int main() {
	inp;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ground a;
		cin >> a.w >> a.h;
		pq.push(a);
	}
	for (int i = 1; i <= n; i++) {
		ground now = pq.top();
		pq.pop();
		while (g.size() >= 1) {
			if (g.back().h <= now.h) {
				g.pop_back();
			}
			else break;
		}
		g.push_back(now);
	}
	dp[0] = g[0].w * g[0].h;
	line a(g[0].h, 0);
	v.push_back(a);
	//cht
	for (int i = 1; i < g.size(); i++) {
		//y = ax + b의 구성요소 제작
		ll x = g[i].w;
		line t(g[i].h, dp[i - 1]);
		

		//교점확인
		while (v.size() >= 1) {
			t.s = cont(t, v.back());

			if (t.s < v.back().s) {
				v.pop_back();
			}
			else break;
		}

		v.push_back(t);

		//이분탐색
		int gg = 0, right = v.size() - 1, left = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (v[mid].s < x) {
				gg = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		//dp 테이블 구성
		dp[i] = v[gg].b + v[gg].a * x;
	}
	cout << dp[g.size() - 1];
}