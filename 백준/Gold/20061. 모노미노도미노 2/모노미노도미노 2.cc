#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int blue[4][6];
int green[6][4];
int ans = 0;


int gmax(int a) {
	int k = 5;
	for (int i = 1; i <= 4; i++) {
		if (green[i + 1][a] == 1) {
			k = i;
			break;
		}
	}
	return k;
}
int bmax(int a) {
	int k = 5;
	for (int i = 1; i <= 4; i++) {
		if (blue[a][i+1] == 1) {
			k = i;
			break;
		}
	}
	return k;
}

void gflow() {
	for (int i = 5; i >= 1; i--) {
		for (int j = 0; j <= 3; j++) {
			green[i][j] = green[i - 1][j];
		}
	}
}

void bflow() {
	for (int i = 5; i >= 1; i--) {
		for (int j = 0; j <= 3; j++) {
			blue[j][i] = blue[j][i - 1];
		}
	}
	
}

void gclear(int a) {
	for (int i = 0; i <= 3; i++) {
		if (green[a][i] == 0) {
			return;
		}
	}
	ans++;
	for (int i = a; i >= 2; i--) {
		for (int j = 0; j <= 3; j++) {
			green[i][j] = green[i - 1][j];
		}
	}
}

void bclear(int a) {
	for (int i = 0; i <= 3; i++) {
		if (blue[i][a] == 0) {
			return;
		}
	}
	ans++;
	for (int i = a; i >= 2; i--) {
		for (int j = 0; j <= 3; j++) {
			blue[j][i] = blue[j][i - 1];
		}
	}
}


int main() {
	inp;
	int n;
	int a;
	cin >> n;
	while (n--) {
		int t, x, y;
		cin >> t >> x >> y;
		switch (t) {
		case 1:
			a = bmax(x);
			blue[x][a] = 1;
			if (a == 1) bflow();
			else bclear(a);

			a = gmax(y);
			green[a][y] = 1;
			if (a == 1) gflow();
			else gclear(a);

			break;
		case 2:
			a = min(gmax(y), gmax(y + 1));
			green[a][y] = 1;
			green[a][y + 1] = 1;
			if (a <= 1)gflow();
			else gclear(a);

			a = bmax(x);
			blue[x][a] = 1;
			if (a == 1) bflow();
			else bclear(a);

			a = bmax(x);
			blue[x][a] = 1;
			if (a == 1) bflow();
			else bclear(a);

			break;
		case 3:
			a = gmax(y);
			green[a][y] = 1;
			if (a == 1)gflow();
			else gclear(a);

			a = gmax(y);
			green[a][y] = 1;
			if (a == 1)gflow();
			else gclear(a);

			a = min(bmax(x), bmax(x + 1));
			blue[x][a] = 1;
			blue[x + 1][a] = 1;
			if (a <= 1)bflow();
			else bclear(a);
		}
	}
	int num = 0;
	for (int i = 2; i <= 5; i++) {
		for (int j = 0; j <= 3; j++) {
			num += blue[j][i];
			num += green[i][j];
		}
	}

	cout << ans << endl;
	cout << num;
}