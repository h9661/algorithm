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

int N;

int main() {
	fastio;
	cin >> N;

	int dpM1, dpM2, dpM3;
	int dpN1, dpN2, dpN3;
	cin >> dpM1 >> dpM2 >> dpM3;
	dpN1 = dpM1, dpN2 = dpM2, dpN3 = dpM3;

	int a, b, c;
	int x, y, z;
	for (int i = 0; i < N - 1; i++) {
		a = dpM1, b = dpM2, c = dpM3;
		x = dpN1, y = dpN2, z = dpN3;
		int temp1, temp2, temp3;
		cin >> temp1 >> temp2 >> temp3;

		dpM1 = max(a + temp1, b + temp1);
		dpN1 = min(x + temp1, y + temp1);

		dpM2 = max(a + temp2, b + temp2);
		dpM2 = max(dpM2, c + temp2);
		dpN2 = min(x + temp2, y + temp2);
		dpN2 = min(dpN2, z + temp2);

		dpM3 = max(b + temp3, c + temp3);
		dpN3 = min(y + temp3, z + temp3);
	}

	int ansMax = max(dpM1, dpM2);
	ansMax = max(ansMax, dpM3);

	int ansMin = min(dpN1, dpN2);
	ansMin = min(ansMin, dpN3);

	cout << ansMax << " " << ansMin << endl;
}