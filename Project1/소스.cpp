#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int C;
	cin >> C;

	while (C--) {
		int N;
		cin >> N;
		vector<int> arr(N, 0);
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		double average = (double)accumulate(arr.begin(), arr.end(), 0) / N;

		int cnt = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] > average)
				cnt++;
		}

		printf("%.3f%%\n", ((double)cnt / N) * 100);
	}
}