#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int N;
	cin >> N;

	int adder = 6;
	int k = 1;
	int sum = 1;

	while (N > sum) {
		sum += adder;
		adder += 6;
		k += 1;
	}

	cout << k << endl;
}