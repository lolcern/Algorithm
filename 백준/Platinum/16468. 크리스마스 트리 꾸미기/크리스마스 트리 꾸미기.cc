#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 100030001
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

ll dp[303][303];
ll pre[303][303];//i번째 층까지 j개로 만들 수 있는 경우의 수
int tmp;

int main() {
	inp;

	ll n, k;
	cin >> k >> n;

	dp[0][0] = 1;
	dp[1][1] = 1;
	dp[2][2] = 2;
	dp[2][3] = 1;
	pre[0][0] = 1;
	pre[1][0] = 1;
	pre[2][0] = 1;
	pre[1][1] = 1;
	pre[2][1] = 1;
	pre[2][2] = 2;
	pre[2][3] = 1;


	for (int i = 3; i <= n; i++) {
		int mxl = k;
		if (i < 9 && pow(2, i) - 1 < k)mxl = pow(2, i) - 1;

		for (int j = i; j <= mxl; j++) {
			//왼쪽만 i-1개의 높이가 있을때
			for (int l = i - 1; l < j; l++) {// l개의 볼을 왼쪽에 쓸때
				dp[i][j] += dp[i - 1][l] * pre[i - 2][j - l - 1];
				dp[i][j] %= MOD;
			}
			//오른쪽만 i-1개의 높이가 있을때 : x2
			dp[i][j] *= 2;
			dp[i][j] %= MOD;
			//둘 다 i-1개의 높이가 있을때
			for (int l = i - 1; l < j; l++) { //l개의 볼을 왼쪽에 쓸때
				dp[i][j] += dp[i - 1][l] * dp[i - 1][j - l - 1];
				dp[i][j] %= MOD;
			}
			pre[i][j] = pre[i - 1][j] + dp[i][j];
			pre[i][j] %= MOD;
		}
		for (int j = 0; j < i; j++) {
			pre[i][j] = pre[i - 1][j];
		}
	}
	

	cout << dp[n][k] << endl;
}