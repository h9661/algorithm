#include <bits/stdc++.h>
#define endl '\n'
#define ii pair<long long, long long>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<ii> arr;
	for (int i = 0; i < N; i++) {
		long long start, end;
		cin >> start >> end;

		arr.push_back({ start, end });
	}

	sort(arr.begin(), arr.end(), [](ii a, ii b) {
		if (a.second != b.second)
			return a.second < b.second;
		else
			return a.first < b.first;
		});

	int count = 0;
	long long end = 0;

	for (int i = 0; i < N; i++) {
		if (end <= arr[i].first) {
			end = arr[i].second;
			count++;
		}
	}

	cout << count << endl;
}