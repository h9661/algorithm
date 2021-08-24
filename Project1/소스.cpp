#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 500000 + 1;
int n, m;
int root[MAX];

int _find(int x) {
	if (root[x] == x) 
		return x;

	return root[x] = _find(root[x]);
}

void _union(int x, int y) {
	int rx = _find(x);
	int ry = _find(y);

	if (rx < ry)
		root[ry] = rx;
	else
		root[rx] = ry;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		root[i] = i;

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		if (_find(u) == _find(v)) {
			cout << i << endl;
			return 0;
		}
		else
			_union(u, v);
	}

	cout << "0" << endl;

	return 0;
}