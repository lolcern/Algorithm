#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

int par[200003];
vector<int> line[200003];
bool in[200003];
int num[200003];
stack<bool> s;
stack<int> q;

int find(int x) {
	if (x == par[x]) return x;
	else return par[x] =  find(par[x]);
}

bool uni(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a == b)return false;
	par[a] = b;
	num[b] += num[a];
	return true;
}


int main() {
	inp;
	fill(num, num + 200003, 1);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		line[a].push_back(b);
		line[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		q.push(a);
	}
	s.push(false);
	in[q.top()] = true;
	int rot = q.top();
	q.pop();
	int nm = 1;
	while (!q.empty()) {
		if (nm == num[find(rot)]) s.push(true);
		else s.push(false);


		in[q.top()] = true;
		for (auto a : line[q.top()]) {
			if (in[a]) uni(a, q.top());
		}
		q.pop();
		nm++;
	}

	if (nm == num[find(rot)]) s.push(true);
	else s.push(false);

	while (!s.empty()) {
		if (s.top()) cout << "CONNECT" << endl;
		else cout << "DISCONNECT" << endl;
		s.pop();
	}

}