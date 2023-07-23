#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<double, double> p;
typedef long long int ll;

double ans;
p a[30];
int n;
p sum;

void dfs(p s,int now = 0, int l = 0, int lst = 0) {
	if (now == n / 2) {
		p tmp = make_pair(2 * s.first - sum.first, 2 * s.second - sum.second);
		ans = min(ans, sqrt(pow(tmp.first, 2) + pow(tmp.second, 2)));
		return;
	}

	for (int i = lst+1; i <= n; i++) {
		if ((l & 1 << i) == 0) {
			int aaa = (l | 1 << i);
			p ss = s;
			ss.first += a[i].first;
			ss.second += a[i].second;
			dfs(ss,now + 1, aaa, i);
		}
	}
}

int main() {
	inp;
	int t;
	cin >> t;
	while (t--)
	{
		sum.first = 0;
		sum.second = 0;
		ans = INF;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			double v,w;
			cin >> v >> w;
			a[i].first = v;
			a[i].second = w;
			sum.first += v;
			sum.second += w;
		}
		dfs(make_pair(0,0));
		cout.precision(20);
		cout << ans << endl;
	}
}