#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
#define N 10000
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

priority_queue<int> pqlower;
priority_queue<int, vector<int>, greater<>> pqupper;
int now;
queue<int> ans;
int m, M;

int main() {
	inp;

	int T;
	cin >> T;
	for (int asdf = 1; asdf <= T; asdf++) {
		int m;
		cin >> m;
		int a;
		cin >> now;
		ans.push(now);
		for (int i = 2; i <= m; i++) {
			cin >> a;
			if (i & 1) {
				//해야함
				if (a > now) {
					if (pqupper.size() < pqlower.size()) {
						pqupper.push(a);
					}
					else {
						pqlower.push(now);
						if (pqupper.top() < a) {
							now = pqupper.top();
							pqupper.pop();
							pqupper.push(a);
						}
						else {
							now = a;
						}
					}
				}
				else {
					if (pqupper.size() > pqlower.size()) {
						pqlower.push(a);
					}
					else {
						pqupper.push(now);
						if (pqlower.top() > a) {
							now = pqlower.top();
							pqlower.pop();
							pqlower.push(a);
						}
						else {
							now = a;
						}
					}
				}
				ans.push(now);
			}
			else {
				if (a > now) {
					pqupper.push(a);
				}
				else {
					pqlower.push(a);
				}
			}
		}

		cout << ans.size() << endl;
		int x = ans.size();
		for(int i = 1; i <= x; i++) {
			cout << ans.front() << " ";
			ans.pop();
			if (i % 10 == 0 && i != x) {
				cout << endl;
			}
		}
		cout << endl;
		
		while (!pqlower.empty()) {
			pqlower.pop();
		}
		while (!pqupper.empty()) {
			pqupper.pop();
		}


	}

}