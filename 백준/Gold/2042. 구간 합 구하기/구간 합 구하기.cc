#include <bits/stdc++.h>
#define size 1000000
using namespace std;
typedef long long int ll;

int N,M,K;

ll tree[size * 4 + 3];
ll arr[size+3];

ll init(int node = 1, int start = 1, int end = N) {
	if (start == end) {
		return tree[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update( int index, ll diff, int node = 1, int start = 1, int end = N) {
	if (start > index || end < index) {
		return;
	}

	tree[node] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(index, diff, node * 2, start, mid);
		update(index, diff, node * 2 + 1, mid + 1, end);
	}
}

ll sum(int left, int right, int node = 1, int start = 1, int end = N) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return sum(left, right, node * 2, start, mid) + sum(left, right, node * 2 + 1, mid + 1, end);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);
	
	cin >> N >> M >> K;
	ll a, b, c;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	init();
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c - arr[b]);
			arr[b] = c;
		}
		else {
			cout << sum(b, c) << "\n";
		}
	}

	


}