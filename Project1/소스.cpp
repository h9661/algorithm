#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 50 + 1;
bool check[MAX];
vector<int> arr;
vector<int> store(6);
int k;

void dfs(int count) {
	if (count == 6){
		if (is_sorted(store.begin(), store.end())) {
			for (auto i : store)
				cout << i << " ";
			cout << endl;
		}

		return;
	}

	for (int i = 0; i < arr.size(); i++) {
		if (check[arr[i]] == false) {
			check[arr[i]] = true;

			store[count] = arr[i];
			dfs(count + 1);

			check[arr[i]] = false;
		}
	}
}

int main() {
	while (1) {
		arr.clear();
		cin >> k;

		if (k == 0)
			break;

		for (int i = 0; i < k; i++) {
			int num;
			cin >> num;

			arr.push_back(num);
		}

		dfs(0);
		cout << endl;
	}
}