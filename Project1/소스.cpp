#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int g_count = 0;
int g_r, g_c;

void DC(int r, int c, int N, int num) {
	if (abs(r - g_r) + abs(c - g_c) > pow(2, N + 1))
		return;

	if (N == 0) {
		if (r == g_r and c == g_c)
			cout << num << endl;
	}
	else {
		DC(r, c, N - 1, num);
		DC(r, c + pow(2, N - 1), N - 1, num + pow(4, N - 1) * 1);
		DC(r + pow(2, N - 1), c, N - 1, num + pow(4, N - 1) * 2);
		DC(r + pow(2, N - 1), c + pow(2, N - 1), N - 1, num + pow(4, N - 1) * 3);
	}
}

int main() {
	int N;
	cin >> N >> g_r >> g_c;

	DC(0, 0, N, 0);
}