#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int k, int end) {
	int n = arr.size() / k;
	int count = 0;
	int adder = 0;
	while (count < k) {
		sort(arr.begin() + adder, arr.begin() + adder + n);
		adder += n;
		count++;
	}
	
	if (k == end)
		return;

	solve(arr, k / 2, end);
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int k;
	cin >> k;

	solve(arr, n / 2, k);

	for (auto i : arr)
		cout << i << " ";

	return 0;
}