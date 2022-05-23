#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int N;
	cin >> N;
	bool flag = false;

	for (int i = 1; i < N; i++) {
		int x = i;
		int sum = i;

		int k = (int)log10(i) + 1;

		while (k >= 0) {
			sum += (x / (int)pow(10, k)) % 10;
			k -= 1;
		}

		if (sum == N) {
			cout << i << endl;
			flag = true;
			break;
		}
	}
	
	if (flag == false)
		cout << 0 << endl;
}