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
	int N;
	cin >> N;
	vector<int> arr(N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int Y = 0;
	int M = 0;

	for (int i = 0; i < N; i++) {
		Y += ((arr[i] / 30) + 1) * 10;
		M += ((arr[i] / 60) + 1) * 15;
	}

	if (M < Y)
		cout << "M" << " " << M << endl;
	else if (M > Y)
		cout << "Y" << " " << Y << endl;
	else
		cout << "Y" << " " << "M" << " " << Y << endl;
}