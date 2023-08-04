#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef long long int ll;

int fail[1000003];	
string p;

int main() {
	inp;

	getline(cin, p);
	while (p != ".") {
		memset(fail, 0, sizeof(fail));
	int n = p.size();
		//fail 구하기
		for (int i = 1, j = 0; i < n; i++) {
			while (j > 0 && p[i] != p[j])j = fail[j - 1];
			if (p[i] == p[j])fail[i] = ++j;
		}
		int ans = n / (n - fail[n - 1]);
		if (n % (n - fail[n - 1]) != 0) {
			cout << 1 << endl;
		}
		else
		cout << ans << endl;

		getline(cin, p);
	}
	


	

}