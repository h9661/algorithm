#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<bool> availibleNumber(10, true);
	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;

		availibleNumber[x] = false;
	}

	int min_number = 1e9;
	int key_channel = 1e9;
	for (int number = 0; number <= 1000000; number++) {
		string str_number = to_string(number);
		bool flag = false;

		for (int i = 0; i < str_number.size(); i++) {
			if (availibleNumber[str_number[i] - '0'] == false) {
				flag = true;
				break;
			}
		}

		if (flag)
			continue;

		if (abs(N - number) < min_number) {
			key_channel = number;
			min_number = abs(N - number);
		}
	}

	int answer_1 = to_string(key_channel).size();
	answer_1 += abs(N - key_channel);
	int answer_2 = abs(N - 100);
	
	cout << min(answer_1, answer_2) << endl;
}