#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;
typedef vector<vector<ll>> mat;

mat first(3, vector<ll>(3, 0));

mat matm(mat a, mat b) {
	mat c(3,vector<ll>(3,0));
	c[1][1] = ((a[1][1] * b[1][1] % MOD) + (a[2][1] * b[1][2]%MOD))%MOD;
	c[1][2] = ((a[1][1] * b[2][1]%MOD) + (a[2][1] * b[2][2]%MOD))%MOD;
	c[2][1] = ((a[1][2] * b[1][1]%MOD) + (a[2][2] * b[1][2]%MOD))%MOD;
	c[2][2] = ((a[1][2] * b[2][1]%MOD) + (a[2][2] * b[2][2]%MOD))%MOD;
	return c;
}

mat power(mat a, ll b) {
	if (b == 1) {
		return first;
	}
	if (b & 1) {
		b /= 2;
		mat aa = power(a, b);
		return matm(matm(aa, aa), first);
	}
	else {
		b /= 2;
		mat aa = power(a, b);
		return matm(aa, aa);
	}
}




int main() {
	inp;

	first[1][1] = 1;
	first[1][2] = 1;
	first[2][1] = 1;
	first[2][2] = 0;
	ll n;
	cin >> n;
	n++;
	if (n & 1) {
		n++;
	}
	//n번째 피보나치 수열 구해야함
	mat jj =  power(first, n-1);
	if (jj[1][2] == 0) cout << MOD;
	else cout << jj[1][2] - 1;
}