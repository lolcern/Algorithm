#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

string a, b;
vector<int> v;
int cnt[11];
int can[11];

int main() {
	inp;

	cin >> a >> b;
	for (int i = 0; i < a.size(); i++) {
		can[a[i] - '0']++;
	}
	for (int i = 0; i < b.size(); i++) {
		cnt[b[i] - '0']++;
		can[b[i] - '0']--;
	}
	
	for (int i = 0; i < a.size(); i++) { //i부터 찾기 시작한다
		for (int j = 9; j >= 0; j--) { //가장 가까이 있는 j를 찾는다
			if (can[j] == 0)continue;
			int idx = -1;
			int c[11] = { 0, };
			for (int k = i; k < a.size(); k++) { //k번째 인덱스에서 찾는다
				if (a[k] == '0' + j) {
					idx = k;
					v.push_back(j);
					can[j]--;	
					break;
				}
				c[a[k] - '0']++;
				if (c[a[k] - '0'] > cnt[a[k] - '0']) break;
			}
			if (idx != -1) {
				
				for (int k = 0; k <= 9; k++) {
					cnt[k] -= c[k];
				}
				i = idx;
				break;
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
}