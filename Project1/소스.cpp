#include <bits/stdc++.h>
#pragma warning (disable : 4996)
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

	vector<ll> cost(N - 1, 0);
	vector<ll> city(N, 0);

	for (int i = 0; i < N - 1; i++)
		cin >> cost[i];

	for (int i = 0; i < N; i++)
		cin >> city[i];

	ll temp = city[0];
	ll i = 0;
	ll j = 1;
	ll gas = 0;
	ll money = 0;

	while (j < N) {
		gas += cost[i];

		if (temp >= city[j]) {
			money += gas * temp;
			temp = city[j];
			gas = 0;
		}

		i += 1;
		j += 1;
	}

	money += gas * temp;


	cout << money << endl;
}