#include <bits/stdc++.h>
#define ULL unsigned long long
#define LL long long int
#define UI unsigned int
#define endl '\n'
#define FASTIO (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#pragma warning(disable : 4996)
using namespace std;

const int MAX = 1000000 + 1;
int arr[MAX];
int check[MAX];
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

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	FASTIO;
	vector<pair<int, int>> pairArr;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		pairArr.push_back({ A, B });
	}

	sort(pairArr.begin(), pairArr.end(), cmp);

	for (int i = 0; i < N; i++)
		arr[i] = pairArr[i].second;

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
	cout << N - (j + 1) << endl;

	for (int i = N - 1; i >= 0; i--) {
		if (idxArr[i] == k) {
			check[arr[i]] = true;
			k--;
			continue;
		}
	}

	for (int i = 0; i < N; i++) {
		if (check[pairArr[i].second] == false)
			cout << pairArr[i].first << endl;
	}

	return 0;
}