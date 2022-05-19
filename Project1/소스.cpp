#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int i = 0;
	int num = 1;
	stack<int> stk;
	vector<char> op;

	while (i < arr.size()) {
		if (op.size() > n * 2)
			break;

		if (stk.size() == 0) {
			stk.push(num);
			num += 1;
			op.push_back('+');
		}

		if (stk.top() == arr[i]) {
			stk.pop();
			op.push_back('-');
			i += 1;
		}
		else {
			stk.push(num);
			num += 1;
			op.push_back('+');
		}
	}

	if (op.size() == n * 2) {
		for (auto x : op)
			cout << x << endl;
	}
	else
		cout << "NO" << endl;
}