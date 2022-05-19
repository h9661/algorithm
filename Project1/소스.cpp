#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 0;
	int number = 1;

	while (count <= 10000) {
		if (to_string(number).find("666") != string::npos) {
			count++;
		}

		if (count == N) {
			cout << number << endl;
			break;
		}

		number++;
	}
}