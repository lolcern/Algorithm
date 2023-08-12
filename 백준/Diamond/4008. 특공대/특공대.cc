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

double cont(line &a, line &b){
	return (double)(b.b - a.b) / (a.a - b.a);
}

int n;
ll a,b,c;
ll pre[1000003];
vector<line> v;
ll dp[1000003];

int main() {
	inp;
	cin >> n;
	cin >> a >> b >> c;
	for (int i = 1; i <= n; i++) {
		ll t;
		cin >> t;
		pre[i] = pre[i - 1] + t;
	}
	dp[1] = a * pre[1] * pre[1] + b * pre[1] + c;
	line st(0,0);
	v.push_back(st);
	//cht
	for (int i = 2; i <= n; i++) {
		ll x = -2 * a * pre[i];
		line t(pre[i-1], a * pow(pre[i-1],2) - b * pre[i-1] + dp[i - 1]);

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
		int g = 0, right = v.size() - 1, left = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (v[mid].s < x) {
				g = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		dp[i] = v[g].a * x + v[g].b + a * pow(pre[i],2) + b * pre[i] + c;
	}
	cout << dp[n];
}