#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> woods(N, 0);
	for (int i = 0; i < N; i++)
		cin >> woods[i];

	int left = 0;
	int right = *max_element(woods.begin(), woods.end());

	while (left <= right) {
		long long sum = 0;
		long long middle = (left + right) / 2;

		for (int i = 0; i < woods.size(); i++) {
			if (woods[i] - middle >= 0)
				sum += woods[i] - middle;
		}

		if (sum >= M)
			left = middle + 1;
		else
			right = middle - 1;
	}

	cout << left - 1 << endl;
}