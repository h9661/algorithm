#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

int N, M;
vector<bool> check(9, false);
vector<int> nums;
vector<int> arr;

void dfs(int k, int count) {
	if (count == M) {

			for (auto i : arr)
				cout << i << " ";

			cout << endl;
		
	}
	else {
		for (int i = 0; i < N; i++) {
			if (check[i] == false) {
				check[i] = true;

				arr.push_back(nums[i]);
				dfs(0, count + 1);
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


	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		nums.push_back(temp);
	}
	
	sort(nums.begin(), nums.end());

	dfs(0, 0);
}