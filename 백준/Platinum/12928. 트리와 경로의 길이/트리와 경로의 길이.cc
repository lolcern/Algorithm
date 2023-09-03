#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

bool dp[51][1001];
queue<p> q;

int main() {
	inp;
	q.push({ 2,0 });
	int n, s;
	cin >> n >> s;

	while (!q.empty()) {
		p now = q.front();
		q.pop();
		int a = 0;
		for (int i = 1; i <= 50; i++) {
			a += i;
			if (now.first + i <= 50 && now.second + a <= 1000) {
				if (!dp[now.first + i][now.second + a]) q.push({ now.first + i, now.second + a });
				dp[now.first + i][now.second + a] = true;
			}
			else break;
		}
	}

	if (dp[n][s])cout << "1";
	else cout << "0";

}