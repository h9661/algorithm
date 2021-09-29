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
	int tc;
	cin >> tc;

	int result = 0;

	while (tc--) {
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		// �� (x1, y1)�� �� (x2, y2) ������ �Ÿ�
		double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		// �� ���� ������ ��
		double subtract = r1 > r2 ? r1 - r2 : r2 - r1;
	
		if (d == 0 && r1 == r2)
			result = -1;
		else if ((d < r1 + r2) && (subtract < d))
			result = 2;
		else if ((d == r1 + r2) || (subtract == d))
			result = 1;
		else
			result = 0;

		cout << result << endl;
	}
}