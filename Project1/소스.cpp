#include <bits/stdc++.h>
using namespace std;

int main() {
	int K, N;
	cin >> K >> N;

	vector<int> arr(K, 0);
	for (int i = 0; i < K; i++)
		cin >> arr[i];

	long long left = 1;
	long long right = *max_element(arr.begin(), arr.end());

	while (left <= right) {
		long long cnt = 0;
		long long middle = (left + right) / 2;

		for (int i = 0; i < arr.size(); i++)
			cnt += arr[i] / middle;
		
		if (cnt >= N)
			left = middle + 1;
		else
			right = middle - 1;
	}

	cout << left - 1 << endl;
}