#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

map<char, pair<char, char>> tree;

void preOrder(char node) {
	cout << node;
	if (tree[node].first != '.')
		preOrder(tree[node].first);
	if (tree[node].second != '.')
		preOrder(tree[node].second);
}

void inOrder(char node) {
	if (tree[node].first != '.')
		inOrder(tree[node].first);
	cout << node;
	if (tree[node].second != '.')
		inOrder(tree[node].second);
}

void postOrder(char node) {
	if (tree[node].first != '.')
		postOrder(tree[node].first);
	if (tree[node].second != '.')
		postOrder(tree[node].second);
	cout << node;
}

int main() {
	int N;
	cin >> N;

	char a, b, c;
	cin >> a >> b >> c;

	tree['A'] = { b, c };

	for (int i = 0; i < N - 1; i++) {
		char p, l, r;
		cin >> p >> l >> r;

		tree[p] = { l, r };
	}

	preOrder('A');
	cout << endl;
	inOrder('A');
	cout << endl;
	postOrder('A');
	cout << endl;
}