#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

p lis[2003];
ll arr[2003];

int main() {
	inp;

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[n-i+1];
	}
	
	lis[0] = { 1,0 };
	for (int i = 1; i <= n; i++) {
		lis[i] = { 1,1 };
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				lis[i].first = max(lis[i].first, lis[j].first + 1);
			}
			else if (arr[j] > arr[i]) {

				lis[i].second = max(lis[i].second, lis[j].second + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = max(ans, lis[i].first + lis[i].second - 1);
	}
	cout << ans;

}