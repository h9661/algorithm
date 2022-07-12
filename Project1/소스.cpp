#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

long long pow(long long a, long long b, long long c) {
	long long retval = 1;

	while (b) {
		if (b & 1)
			retval *= a;

		a *= a;
		b /= 2;
		retval %= c;
	}

	return retval;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	cout << pow(a, b, c) << endl;
}