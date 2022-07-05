#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

vector<bool> check(10001, false);
int N, M;
vector<int> arr;
vector<int> ans;

void dfs(int count) {
	if (count == M) {

			for (auto i : ans)
				cout << i << " ";
			cout << endl;
	}
	else {
		int k = 0;

		for (int i = 0; i < arr.size(); i++) {
			if (check[i] == false and arr[i] != k) {
				check[i] = true;
				k = arr[i];

				ans.push_back(arr[i]);
				dfs(count + 1);
				ans.pop_back();

				check[i] = false;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());


	dfs(0);
}