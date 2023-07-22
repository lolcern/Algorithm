#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

deque<int> d; 
int a[5000003];
int main() {
	inp;
	int l, n;
	cin >> n >> l;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		//제거 먼저
		if (i > l) {
			if (d.front() == a[i - l]) {
				d.pop_front();
			}
		}

		//삽입 나중
		while (!d.empty()) {
			if (d.back() > a[i]) {
				d.pop_back();
			}
			else {
				break;
			}
		}
		d.push_back(a[i]);

		cout << d.front() << " ";

	}

}