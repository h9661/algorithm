#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 3000 + 1;
int arr[MAX];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		if (temp >= 0)
			arr[temp + 1500]++;
		else
			arr[1500 + temp]++;
	}

	for (int i = 0; i <= 3000; i++) {
		if (i >= 1500 && arr[i] != 0) {
			cout << i - 1500 << " ";
		}
		else if (i < 1500 && arr[i] != 0) {
			cout << i - 1500 << " ";
		}
	}

	return 0;
}