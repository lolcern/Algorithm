#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int lst[40003]; //특정 먹이가 마지막으로 나온 위치
int idx[40003]; //먹이 개수 최대 인덱스
int dp[40003];

int main() {
	inp;
	
	fill(dp, dp + 40003, 1000000);
	fill(idx, idx + 300, 1);
	dp[0] = 0;
	int n, m;
	cin >> n >> m;
	int sqrtn = sqrt(n);
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		for (int j = sqrtn; j >= 2; j--) {
			if (lst[a] < idx[j]) {
				idx[j] = idx[j - 1];
			}
		}
		if (lst[a] != i - 1) idx[1] = i;
		lst[a] = i;

		for (int j = 1; j <= sqrtn; j++) {
			dp[i] = min(dp[i], dp[idx[j] - 1] + j * j);
		}

	}
	cout << dp[n];
}