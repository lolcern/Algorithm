#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int arr[100003];
int arr2[100003];

bool corr;
bool ddok = true;

int main() {
	inp;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> arr2[i];
		if (i > 2) {
			if (arr2[i] > arr2[i - 1] && arr2[i - 1] > arr2[i - 2]) corr = true;
			if (arr2[i] < arr2[i - 1] && arr2[i - 1] < arr2[i - 2]) corr = true;
		}
		if (arr2[i] != arr[i])ddok = false;

	}
	if (ddok || corr) {
		cout << "POSSIBLE";
	}
	else {	 
		cout << "IMPOSSIBLE";
	}
}