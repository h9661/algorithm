#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

const int MAX = 4000000 + 1;
int primeNumber[MAX];
vector<int> arr;
int N;

void eratos() {
	for (int i = 2; i <= N; i++)
		primeNumber[i] = i;


	for (int i = 2; i <= N; i++) {
		if (primeNumber[i] == 0)
			continue;

		for (int j = i + i; j <= N; j += i)
			primeNumber[j] = 0;
	}
}

int main() {
	cin >> N;

	eratos();

	for (int i = 2; i <= N; i++) {
		if (primeNumber[i] != 0)
			arr.push_back(primeNumber[i]);
	}


	int start = 0;
	int end = 0;
	int sum = 0;
	int count = 0;

	arr.push_back(1e9);

	while (end < arr.size()) {
		if (sum <= N)
			sum += arr[end++];
		else if (sum > N)
			sum -= arr[start++];

		if (sum == N)
			count++;
	}

	cout << count << endl;

	return 0;
}