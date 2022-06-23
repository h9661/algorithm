#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			sum += arr[j];
		}
	}

	cout << sum << endl;
}