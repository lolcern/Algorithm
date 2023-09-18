#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;



int main() {
	inp;
	int n;
	cin >> n;
	int x = 0;
	while (n--) {
		int a;
		cin >> a;
		x ^= a;
	}
	if (x) {
		cout << "koosaga";
	}
	else {
		cout << "cubelover";
	}

}