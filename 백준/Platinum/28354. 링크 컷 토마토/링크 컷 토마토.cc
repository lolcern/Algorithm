#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

set<int> s[300000];
vector<p> trans[300003];
int ik[300003];
queue<p> q;
queue<int> q2;
int maxday;

int main() {
	inp;
	int n, m, k, qq;
	cin >> n >> m >> k >> qq;
	memset(ik, -1, sizeof(ik));

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		s[a].insert(b);
		s[b].insert(a);
	}
	for (int i = 1; i <= k; i++) {
		int a;
		cin >> a;
		ik[a] = 0;
		q.push({ 0,a });
	}
	for (int i = 1; i <= qq; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		trans[a].push_back({ b,c });
		maxday = max(maxday, a);
	}

	for (int i = 0; i <= maxday + n + 3; i++) {
		//tran 부분
		if (i <= maxday + 1) {
			for (auto a : trans[i]) {
			if (!s[a.first].insert(a.second).second) {
				s[a.first].erase(a.second);
				s[a.second].erase(a.first);
			}
			else {
				s[a.second].insert(a.first);
				if (ik[a.second] != -1) {
					if(ik[a.first] == -1)
					q.push({ i,a.second });
				}
				else if (ik[a.first] != -1) {
					if(ik[a.second] == -1)
					q.push({ i,a.first });
				}
			}
		}
		}
		
		// q 부분
		p now = { -1,-1 };
		if (!q.empty()) now = q.front();
		while (now.first == i) {
			q.pop();
			for (auto a : s[now.second]) {
				if (ik[a] == -1) {
					q.push({ i + 1,a });
					ik[a] = i + 1;
				}
				q2.push(a);
			}
			while (!q2.empty()) {
				s[now.second].erase(q2.front());
				s[q2.front()].erase(now.second);
				q2.pop();
			}
			if (q.empty())break;
			now = q.front();
		}
		
	}
	


	for (int i = 1; i <= n; i++) {
		cout << ik[i] << " ";
	}

}