#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	
	int M;
	cin >> M;

	vector<int> arr2(M, 0);
	for (int i = 0; i < M; i++)
		cin >> arr2[i];

	for (int i = 0; i < M; i++) {
		cout << upper_bound(arr.begin(), arr.end(), arr2[i]) - lower_bound(arr.begin(), arr.end(), arr2[i]) << " ";
	}
}