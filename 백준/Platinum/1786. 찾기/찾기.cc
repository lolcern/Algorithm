#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef long long int ll;

int fail[1000003];	
vector<int> result;
string t, p;

int main() {
	inp;
	getline(cin, t);
	getline(cin, p);
	int m = t.size();
	int n = p.size();
	//fail 구하기
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && p[i] != p[j])j = fail[j - 1];
		if (p[i] == p[j])fail[i] = ++j;
	}


	for (int i = 0, j = 0; i < m; i++) {
		while (j > 0 && t[i] != p[j])j = fail[j - 1];

		if (t[i] == p[j]) {
			if (j == n - 1) {
				result.push_back(i - n + 2);
				j = fail[j];
			}
			else {
				j++;
			}
		}
	}

	cout << result.size() << endl;
	for (auto a : result) {
		cout << a << " ";
	}

}