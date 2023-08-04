#include <bits/stdc++.h>
#define inp ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define INF 999999999
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;

struct Trie {
	Trie* line[26];
	bool isend;
	int num;
	int wordnum;

	Trie() {
		fill(line, line + 26, nullptr);
		isend = false;
		num = 0;
		wordnum = 0;
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (line[i])delete line[i];
		}
	}

	void insert(char* c)
	{
		if (*c == '\0') {
			num++; //?
			isend = true;
			return;
		}
		else {
			int k = *c - 'a';
			if (!line[k]) {
				num++;
				line[k] = new Trie;
			}
			wordnum++;
			line[k]->insert(c + 1);
		}
	}

	ll countkey(bool isfirst = false) {
		ll ret = 0;

		if (isfirst || num > 1)	ret += wordnum;

		for (int i = 0; i < 26; i++) {
			if (line[i])ret += line[i]->countkey();
		}
		return ret;
	}
};

int main() {
	inp;
	ll n;
	cout << fixed;
	cout.precision(2);
	while (cin >> n) {
		Trie* root = new Trie;
		for(int i = 1; i <= n; i++) {
			char c[81];
			cin >> c;
			root->insert(c);
		}
		double ans = (double)root->countkey(true) / n;
		cout << ans << endl;
		delete root;
	}
}