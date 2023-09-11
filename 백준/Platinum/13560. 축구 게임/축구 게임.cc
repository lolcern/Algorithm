#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

vector<int> a;
int sum;

int main() {
	inp;
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int b;
		cin >> b;
		sum += b;
		a.push_back(b);
	}
	sort(a.begin(), a.end());
	for (int i = n - 1; i >= 0; i--) {
		cnt += i;
		if (cnt < a[i]) {
			cout << "-1";
			return 0;
		}
		cnt -= a[i];
	}
	if (cnt == 0)
		cout << "1";
	else cout << "-1";
}