#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

stack<ll> s;
ll ans;

int main() {
	inp;

	int n;
	cin >> n;
	int b;
	cin >> b;
	s.push(b);
	n--;
	while (n--) {
		int a;
		cin >> a;
		//front가 now보다 작다면
		if (s.top() < a) {
			ans += a - s.top();
			while (!s.empty()) {
				s.pop();
				if (s.empty()) {
					break;
				}
				if (s.top() >= a) {
					break;
				}
			}
			if (s.empty()) {
				s.push(a);
				continue;
			}
		}
		if (s.top() == a) {
			continue;
		}
		s.push(a);
	}

	if (s.size() >= 2) {
		int l = s.top();
		int r = 0;
		while (s.size() > 1) {
			s.pop();
			r = s.top();
		}
		ans += r - l;
	}
	cout << ans;
}