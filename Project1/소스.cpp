#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> primeNumber(1001);
void eratos() {
	for (int i = 2; i <= 1000; i++)
		primeNumber[i] = i;

	for (int i = 2; i <= 1000; i++) {
		for (int j = 2 * i; j <= 1000; j += i) {
			primeNumber[j] = 0;
		}
	}
}

int main() {
	int N;
	cin >> N;
	eratos();
	vector<int> arr(N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int count = 0;

	for (int i = 0; i < arr.size(); i++) {
		if (primeNumber[arr[i]] != 0)
			count++;
	}

	cout << count << endl;
}