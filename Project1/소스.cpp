#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

// 백준 14002
// 이분 탐색을 이용한 가장 긴 증가하는 수열

const int MAX = 1000000 + 1;
vector<int> store;
int arr[MAX];
int lis[MAX];
int idxArr[MAX];

int binary_search(int left, int right, int target) {
	int mid;

	while (left < right) {
		mid = (left + right) / 2;

		if (lis[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}

	return right;
}

int main() {
	fastio;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int j = 0;
	int i = 1;
	lis[0] = arr[0];
	idxArr[0] = 0;

	while (i < N) {
		if (lis[j] < arr[i]) {
			lis[j + 1] = arr[i];
			idxArr[i] = j + 1;
			j += 1;
		}
		else {
			int idx = binary_search(0, j, arr[i]);
			lis[idx] = arr[i];
			idxArr[i] = idx;
		}

		i += 1;
	}

	int k = j;
	cout << j + 1 << endl;

	for (int i = N - 1; i >= 0; i--) {
		if (idxArr[i] == k) {
			store.push_back(arr[i]);
			k--;
			continue;
		}
	}

	reverse(store.begin(), store.end());

	for (auto i : store)
		cout << i << " ";

	return 0;
}