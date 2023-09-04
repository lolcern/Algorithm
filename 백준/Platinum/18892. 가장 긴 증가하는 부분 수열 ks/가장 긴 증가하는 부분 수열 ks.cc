#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000000
using namespace std;
typedef long long int ll;
typedef pair<int, ll> p;

int a[503];
int cnt[503];
int len[503];
vector<p> v[503];	
ll n, k;
queue<int> s;

bool cmp(p u, p v) {
	return a[u.first] < a[v.first];
}

int main() {
	inp;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[n + 1] = n + 1;
	cnt[n+1] = 1;
	for (int i = n; i >= 0; i--) {
		for (int j = n+1; j > i; j--) {
			if (a[i] < a[j]) {
				len[i] = max(len[i], len[j] + 1);
			}
		}

		for (int j = n+1; j > i; j--) {
			if (a[i] < a[j]) {
				if (len[j] == len[i] - 1) {
					v[i].push_back({ j,cnt[j]});
					cnt[i] += cnt[j];
					cnt[i] = min(cnt[i], MOD);
				}
			}
		}
		sort(v[i].begin(), v[i].end(), cmp);
	}
	if (cnt[0] < k) {
		cout << "-1";
		return 0;
	}

	int now = 0;
	while (len[now] > 1) {
		for (auto b : v[now]) {
			if (b.second >= k) {
				now = b.first;
				break;
			}
			else {
				k -= b.second;
			}
		}
		s.push(a[now]);
	}

	while (!s.empty()) {
		cout << s.front() << " ";
		s.pop();
	}

}