#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

bool visited[9];
vector<int> ans;
vector<int> arr;
int N, M;

void dfs(int count) {
	if (count == M) {
		if (is_sorted(ans.begin(), ans.end())) {
			for (auto i : ans)
				cout << i << " ";
			cout << endl;
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			ans.push_back(arr[i]);
			dfs(count + 1);
			ans.pop_back();
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	dfs(0);
}