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
	int a_x, a_y, a_z;
	int c_x, c_y, c_z;

	cin >> a_x >> a_y >> a_z;
	cin >> c_x >> c_y >> c_z;

	cout << c_x - a_z << " " << c_y / a_y << " " << c_z - a_x << endl;
}