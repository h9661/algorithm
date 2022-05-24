#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> arr(N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			else {
				for (int k = 0; k < N; k++) {
					if (i == k or j == k)
						continue;
					else {
						if (sum < arr[i] + arr[j] + arr[k] && arr[i] + arr[j] + arr[k] <= M)
							sum = arr[i] + arr[j] + arr[k];
					}
				}
			}
		}
	}

	cout << sum << endl;
}