#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<double, int> p;
typedef long long int ll;

struct compare {
	bool operator()(p& a, p& b) {
		return a.first / a.second < b.first / b.second;
	}
};

priority_queue<p,vector<p>, compare> pq;
double lo = MOD;
double ans = MOD;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		double a;
		cin >> a;
		pq.push({a,1});
		lo = min(lo, a);
	}
	int m;
	cin >> m;
	ans = pq.top().first - lo;
	while (m--) {
		p now = pq.top();
		pq.pop();
		now.second++;
		lo = min(lo, now.first / now.second);
		pq.push(now);
		ans = min(ans, pq.top().first / pq.top().second - lo);
	}
	cout << fixed;
	cout.precision(10);
	cout << ans;
}