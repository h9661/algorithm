#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 25 + 1;
vector<pair<int, bool>> tree[MAX];

void preOrder(int node) {
	cout << (char)(node + 'A');
	for (int i = 0; i < tree[node].size(); i++)
		preOrder(tree[node][i].first);
}

void inOrder(int node) {
	if (tree[node].size() && tree[node][0].second == true)
		inOrder(tree[node][0].first);

	cout << (char)(node + 'A');

	if (tree[node].size() && tree[node][0].second == false)
		inOrder(tree[node][0].first);
	else if (tree[node].size() == 2)
		inOrder(tree[node][1].first);
}

void postOrder(int node) {
	for (int i = 0; i < tree[node].size(); i++)
		postOrder(tree[node][i].first);

	cout << (char)(node + 'A');
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		char a, b, c;
		cin >> a >> b >> c;

		if (b != '.')
			tree[a - 'A'].push_back({ b - 'A', true });

		if (c != '.')
			tree[a - 'A'].push_back({ c - 'A' , false });
	}

	preOrder(0);
	cout << endl;
	inOrder(0);
	cout << endl;
	postOrder(0);
	cout << endl;

	return 0;
}