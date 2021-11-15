#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 6385)
#pragma warning (disable : 6386)
#pragma warning (disable : 6200)
#pragma warning (disable : 26812)
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

	vector<pii> parr;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		parr.push_back({ a, b });
	}

	sort(parr.begin(), parr.end());

	int ptr = 0;
	int time = 0;

	while (ptr < N) {
		if (time < parr[ptr].first)
			time++;
		else {
			time += parr[ptr].second;
			ptr++;
		}
	}

	cout << time << endl;
}