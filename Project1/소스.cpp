#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 6385)
#pragma warning (disable : 6386)
#pragma warning (disable : 6200)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int main() {
	fastio;
	int N;
	cin >> N;

	int elapsedTime = 0;
	int count = 0;

	vector<pii> arr;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;

		arr.push_back({ a, b });
	}

	while (count < N) {
		if (((elapsedTime % (arr[count].first + arr[count].second))) < arr[count].second) {
			elapsedTime++;
		}
		else {
			elapsedTime++;
			count++;
		}
	}

	cout << elapsedTime << endl;
}