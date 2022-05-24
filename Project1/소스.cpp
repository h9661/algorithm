#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	for (auto i : arr)
		cout << i << endl;
}