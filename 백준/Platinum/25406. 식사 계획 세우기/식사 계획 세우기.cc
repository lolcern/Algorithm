#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;


priority_queue<int, vector<int>, greater<>> pq[300003]; //pq
set<p> s; //최소 인덱스 반환용
int lst; //마지막에 뭘 했는지
set<p> cnt; //원소별 개수 반환용
int cont[300003];
int n;

int main() {
	inp;
	cin >> n;
	int mx = 0;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		cont[a]++;
		mx = max(mx, cont[a]);
		pq[a].push(i);
	}
	for (int i = 1; i <= n; i++) {
		if (!pq[i].empty()) {
			s.insert({ pq[i].top(),i });
			cnt.insert({ pq[i].size(),i });
		}
	}
	if (mx > ceil(n / (float)2)) {
		cout << "-1";
		exit(0);
	}

	for (int i = n; i >= 2; i--) {
		if ((--cnt.end())->first > ceil((i-1) / (float)2)) { //과반수 도달
			p now = *(--cnt.end());
			cout << pq[now.second].top() << " ";
			s.erase({ pq[now.second].top(),now.second });
			pq[now.second].pop();
			cnt.erase({ cont[now.second], now.second });
			cont[now.second]--;
			cnt.insert({ cont[now.second],now.second });
			if (!pq[lst].empty()) {
				s.insert({ pq[lst].top(),lst });
			}
			lst = now.second;
		}
		else { //아직 과반수 x
			p now = *(s.begin());
			cout << now.first << " ";
			pq[now.second].pop();
			s.erase(now);
			cnt.erase({ cont[now.second], now.second });
			cont[now.second]--;
			if(cont[now.second])
			cnt.insert({ cont[now.second],now.second });
			if (!pq[lst].empty()) {
				
				s.insert({ pq[lst].top(),lst });
			}
			lst = now.second;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!pq[i].empty()) cout << pq[i].top();
	}

}