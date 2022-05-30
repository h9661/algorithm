#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;

int main() {
	int M, N, B;
	cin >> N >> M >> B;

	vector<vector<int>> arr(N, vector<int>(M, 0));

	int max_value = 0;
	int min_value = INF;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];

			if (arr[i][j] > max_value)
				max_value = arr[i][j];
			
			if (arr[i][j] < min_value)
				min_value = arr[i][j];
		}
	}

	vector<pair<int, int>> answer;

	for (int h = min_value; h <= max_value; h++) {
		int time = 0;
		int height = h;
		int block = B;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] > h) {
					time += (arr[i][j] - h) * 2;
					block += arr[i][j] - h;
				}

				if (arr[i][j] < h) {
					time += (h - arr[i][j]);
					block -= h - arr[i][j];
				}
			}
		}

		if (block >= 0) {
			answer.push_back({ time, height });
		}
	}

	sort(answer.begin(), answer.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.first != b.first)
			return a.first < b.first;
		else
			return a.second > b.second;
		});

	cout << answer[0].first << " " << answer[0].second << endl;
}