#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

int N, M;
vector<bool> check(9, false);
vector<int> arr;

void dfs(int k, int count) {
	if (count == M) {
		if (is_sorted(arr.begin(), arr.end())) {
			for (auto i : arr)
				cout << i << " ";

			cout << endl;
		}
	}
	else {
		for (int i = k; i <= N; i++) {
			if (check[i] == false) {
				check[i] = true;

				arr.push_back(i);
				dfs(i + 1, count + 1);
				arr.pop_back();
				
				check[i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	dfs(1, 0);
}