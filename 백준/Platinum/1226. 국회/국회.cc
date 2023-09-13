#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int n;
bool ab[100001];
int par[100001];
vector<p> v;
int sum;
int ans;
stack<int> s;

int main() {
	inp;
	fill(par, par + 100001, -1);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int b;
		cin >> b;
		v.push_back({ b,i });
		sum += b;
	}
	sort(v.begin(), v.end(),greater<p>());
	ab[0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= sum / 2; j++) {
			if (ab[j] && !ab[j+v[i].first] && par[j] != i) {
				ab[j + v[i].first] = true;
				par[j + v[i].first] = i;
				ans = max(ans, j + v[i].first);
			}
		}
	}

	int now = par[ans];
	int rans = 0;
	while (now != -1) {
		rans++;
		s.push(v[now].second);
		int nxt = ans - v[now].first;
		now = par[nxt];
		ans = nxt;
	}

	cout << rans << endl;
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}


}