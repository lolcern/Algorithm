#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

struct Trie{
	Trie* line[10];
	bool isend;
	bool exch;

	Trie() {
		fill(line, line + 10, nullptr);
		isend = false;
		exch = false;
	}

	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (line[i])delete line[i];
		}
	}
	bool insert(const char* k) {
		if (!(*k == '\0')) {
			exch = true;
			int nxt = *k - '0';
			if (!line[nxt])line[nxt] = new Trie;
			return !isend && line[nxt]->insert(k+1);
		}
		else {
			isend = true;
			return !exch;
		}
	}
};

int main() {
	inp;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		Trie* root = new Trie;
		bool result = true;
		while (n--) {
			char ph[15];
			cin >> ph;

			if (!root->insert(ph)) result = false;
		}
		if (result) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		delete root;
	}
}