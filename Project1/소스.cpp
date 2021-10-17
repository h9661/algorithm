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
	int N, M;
	cin >> N >> M;

	int appleCount;
	cin >> appleCount;
	vector<int> arr(appleCount, 0);

	for (int i = 0; i < appleCount; i++)
		cin >> arr[i];

	int startLocation = 1;
	int endLocation = M;
	int movedDist = 0;

	for (int i = 0; i < appleCount; i++) {
		while (1) {
			if (arr[i] >= startLocation && arr[i] <= endLocation) {
				break;
			}
			else if (arr[i] < startLocation) {
				startLocation--;
				endLocation--;
				movedDist++;
			}
			else {
				startLocation++;
				endLocation++;
				movedDist++;
			}
		}
	}

	cout << movedDist << endl;
}