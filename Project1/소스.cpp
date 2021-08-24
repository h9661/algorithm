#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int n, m;
const int MAX = 1000000 + 1;
int root[MAX];

int do_find(int x) {
	if (root[x] == x)
		return x;
	return root[x] = do_find(root[x]);
}

void do_union(int x, int y) {
	int rootX = do_find(x);
	int rootY = do_find(y);

	if (rootX < rootY)
		root[rootY] = rootX;
	else
		root[rootX] = rootY;
}

int main() {
	fastio;
	// 0 a b -> a포함 집합 b 포함 집합 union
	// 1 a b -> a와 b의 루트가 같나 ? YES : NO
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		root[i] = i;

	for (int i = 0; i < m; i++) {
		int op, a, b;
		cin >> op >> a >> b;

		if (op == 0) {
			do_union(a, b);
		}
		else {
			if (do_find(a) == do_find(b))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	

	return 0;
}