#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 6385)
#pragma warning (disable : 6386)
#pragma warning (disable : 6200)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

typedef struct Node {
	int data;
	Node* left;
	Node* right;
}Node;

Node* Insert(Node* node, int data) {
	if (node == NULL) {
		node = new Node();
		node->data = data;
		node->left = node->right = NULL;
	}
	else if (data <= node->data)
		node->left = Insert(node->left, data);
	else
		node->right = Insert(node->right, data);

	return node;
}

void PostOrder(Node* node) {
	if (node->left != NULL)
		PostOrder(node->left);

	if (node->right != NULL)
		PostOrder(node->right);

	cout << node->data << endl;
}

int main() {
	Node* root = NULL;

	int temp;
	while (cin >> temp) {
		if (temp == EOF)
			break;

		root = Insert(root, temp);
	}

	PostOrder(root);
	return 0;
}