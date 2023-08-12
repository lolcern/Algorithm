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
ll a[100003], b[100003];
vector<line> v;
ll dp[100003];

int main() {
	inp;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	for (int i = 2; i <= n; i++) {
		line t(b[i-1], dp[i - 1]);

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
		ll x = a[i];
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
		dp[i] = v[g].a * x + v[g].b;
	}
	cout << dp[n];
}