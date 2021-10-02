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

int main() {
	int N;
	cin >> N;

	stack<int> arr;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		arr.push(temp);
	}

	stack<int> stk;

	vector<int> ans;

	while(arr.size() != 0){
		int num = arr.top();

		if (stk.size() == 0) {
			stk.push(num);
			arr.pop();
			ans.push_back(-1);
			continue;
		}

		if (num < stk.top()) {
			ans.push_back(stk.top());
			stk.push(num);
			arr.pop();
		}
		else
			stk.pop();
	}

	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << " ";

	return 0;
}