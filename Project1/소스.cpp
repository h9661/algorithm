#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

long long init(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
	if (start == end)
		return tree[node] = a[start];
	else
		return tree[node] = (init(a, tree, node * 2, start, (start + end) / 2) * init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end)) % 1000000007;
}

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 1;
	
	if (left <= start && end <= right)
		return tree[node];

	return sum(tree, node * 2, start, (start + end) / 2, left, right) % 1000000007 * sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right) % 1000000007;
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end)
		return;

	if (start == end) {
		tree[node] = tree[node] + diff;
		return;
	}

	update(tree, node * 2, start, (start + end) / 2, index, diff);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));

	vector<long long> a(N, 0);
	vector<long long> tree(tree_size, 0);

	for (int i = 0; i < N; i++)
		cin >> a[i];

	init(a, tree, 1, 0, N - 1);

	M += K;

	while (M--) {
		long long op, b, c;
		cin >> op >> b >> c;

		if (op == 1) {
			b -= 1;
			long long diff = c - a[b];

			a[b] = c;
			update(tree, 1, 0, N - 1, b, diff);
		}
		else {
			b -= 1;
			c -= 1;
			cout << sum(tree, 1, 0, N - 1, b, c) << endl;
		}
	}
}