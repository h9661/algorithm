#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	deque<int> numbers;
	for (int i = 1; i <= N; i++)
		numbers.push_back(i);

	int count = 0;
	vector<int> answer;

	while (numbers.size() != 0) {
		if (count == K - 1) {
			answer.push_back(numbers.front());
			numbers.pop_front();
			count = 0;
		}
		else {
			numbers.push_back(numbers.front());
			numbers.pop_front();
			count++;
		}
	}

	cout << "<";
	for (int i = 0; i < N - 1; i++)
		cout << answer[i] << ", ";
	cout << answer.back();
	cout << ">";
}