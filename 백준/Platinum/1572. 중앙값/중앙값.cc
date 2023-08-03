#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int n;
ll ans;
ll arr[250003];
int N = 131072;
ll tree[300000];

void update(int x) {
	int node = N + x;
	while (node >= 1) {
		tree[node]++;
		node /= 2;
	}
}
void lupdate(int x) {
	int node = N + x;
	while (node >= 1) {
		tree[node]--;
		node /= 2;
	}
}

ll query(int x) {// x번째원소찾기
	ll node = 1;
	while (node <= N) {
		if (tree[node * 2] < x) {
			x -= tree[node * 2];
			node = node * 2 + 1;
		}
		else {
			node = node * 2;
		}
	}
	return node - N;
}


int main() {
	inp;
	int k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(arr[i] + 1);
		if (i >= k + 1) {
			lupdate(arr[i - k] + 1);
		}
		if (i >= k) {
			ans += query((k + 1) / 2) - 1;
		}
	}
	cout << ans;
}