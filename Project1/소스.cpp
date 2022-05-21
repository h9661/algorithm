#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> prime(1000001, 0);

void eratos() {
	for (int i = 2; i <= 1000000; i++)
		prime[i] = i;

	for (int i = 2; i <= 1000000; i++) {
		for (int j = 2 * i; j <= 1000000; j += i)
			prime[j] = 0;
	}
}

int main() {
	eratos();
	int M, N;
	cin >> M >> N;

	for (int i = M; i <= N; i++) {
		if (prime[i] != 0)
			cout << i << endl;
	}
}