#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int n,k;
int arr[100003];
priority_queue<int, vector<int>,greater<>> pq;

int main() {
	inp;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		int now = arr[i];
		if (i <= k) {
			pq.push(now);
			continue;
		}
		if (now < pq.top()) {
			cout << now << " ";
		}
		else {
			cout << pq.top() << " ";
			pq.pop();
			pq.push(now);
		}
	}
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
}