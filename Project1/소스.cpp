#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

map<string, string> root;
map<string, int> m;
vector<int> store;

string do_find(string x) {
	if (root[x] == x)
		return x;
	return root[x] = do_find(root[x]);
}

void do_union(string x, string y) {
	string rootX = do_find(x);
	string rootY = do_find(y);

	if (m[rootX] < m[rootY]) {
		root[rootX] = rootY;
		m[rootY] += m[rootX];
		m[rootX] = 0;
	}
	else {
		root[rootY] = rootX;
		m[rootX] += m[rootY];
		m[rootY] = 0;
	}
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		root.clear();
		m.clear();

		int F;
		cin >> F;

		for (int i = 0; i < F; i++) {
			string x, y;
			cin >> x >> y;

			if (root[x] == "") {
				root[x] = x;
				m[x]++;
			}
			if (root[y] == "") {
				root[y] = y;
				m[y]++;
			}

			if(do_find(x) != do_find(y))
				do_union(x, y);

			store.push_back(m[do_find(x)]);
		}
	}

	for (auto i : store)
		cout << i << endl;

	return 0;
}