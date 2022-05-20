#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr1(N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr1[i];
	sort(arr1.begin(), arr1.end());
	int M;
	cin >> M;
	vector<int> arr2(M, 0);
	for (int i = 0; i < M; i++)
		cin >> arr2[i];

	for (auto i : arr2) {
		if (binary_search(arr1.begin(), arr1.end(), i))
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}