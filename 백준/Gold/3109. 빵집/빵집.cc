#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int r, c;
char grid[10005][505];
int num[505];
int mnum = 0;
int arrive = 0;
int dx[4] = { 0,1,1,1 };
int dy[4] = { 0,-1,0,1 };

bool go(int x,int y) {

	for (int i = 1; i <= 3; i++) {
		int nx = dy[i] + x;
		int ny = dx[i] + y;
		if (nx <= r && nx > 0 && ny <= c && ny > 0) {
			if (grid[nx][ny] == '.') {
				grid[nx][ny] = 'x';
				if (ny == c) {
					arrive++;
					return true;
				}
				if (go(nx, ny)) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	inp;

	cin >> r >> c;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'x') {
				mnum = max(mnum,++num[j]);
			}
		}
	}

	for (int i = 1; i <= r; i++) {
		go(i, 1);
	}

	
	

	cout << arrive;
}