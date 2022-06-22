#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int maxYear = lcm(M, N);
		
		while (1) {
			if (x > maxYear or (x - 1) % N + 1 == y)
				break;

			x += M;
		}
		if (x > maxYear)
			cout << -1 << endl;
		else
			cout << x << endl;
	}
}