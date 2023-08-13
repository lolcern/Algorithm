#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

struct line {
	ll a, b;
};

double cont(line& a, line& b) {
	return (double)(a.b - b.b) / (b.a - a.a);
}

int n;
ll a[200003];
ll pre[200003];
ll c;
ll ans;
int idx;
line v[200003];
double x[200003];

void push(line l) {
	while (idx > 1 && cont(l, v[idx - 2]) > cont(l, v[idx - 1])) idx--;
	if (idx) x[idx - 1] = cont(l, v[idx - 1]);
	v[idx++] = l;
}
ll func(ll X) {
	int go = lower_bound(x, x + idx - 1, X) - x;
	return X * v[go].a + v[go].b;
}

int main() {
	inp;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
		c += i * a[i];
	}
	for (int i = 1; i <= n; i++) {
		//선 추가
		push({i,-pre[i-1]});
		ans = max(ans, func(a[i]) + pre[i - 1] - i * a[i]);
	}
	idx = 0;
	for (int i = n; i >= 1; i--) {
		push({-i,-pre[i]});
		ans = max(ans, func(-a[i]) + pre[i] - i * a[i]);
	}

	cout << ans + c;

}