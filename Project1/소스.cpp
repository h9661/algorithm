#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int main() {
	long long n, k;

	while (cin >> n >> k) {
		long long ans = n;

		while (n >= k) {
			ans += n / k;
			int temp = n % k;
			n /= k;
			n += temp;
		}

		cout << ans << endl;
	}
}