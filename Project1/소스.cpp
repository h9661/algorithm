#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 200 + 1;
int root[MAX];
int N, M;
int cities[10001];

int do_find(int x) {
	if (root[x] == x)
		return x;
	return root[x] = do_find(root[x]);
}

void do_union(int x, int y) {
	int rx = do_find(x);
	int ry = do_find(y);

	if (rx < ry)
		root[ry] = rx;
	else
		root[rx] = ry;
}

int main() {
	cin >> N;
	cin >> M;

	for (int i = 0; i < MAX; i++)
		root[i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp;
			cin >> temp;

			if (temp == 1)
				do_union(i, j);
		}
	}


	for (int i = 0; i < M; i++)
		cin >> cities[i];

	int k = do_find(cities[0]);

	for (int i = 0; i < M; i++) {
		if (k != do_find(cities[i])) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	return 0;
}