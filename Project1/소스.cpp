#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

bool cmp1(int a, int b) {
	return a < b;
}

bool cmp2(int a, int b) {
	return a > b;
}

int main() {
	int N;
	cin >> N;

	vector<int> A(N);
	vector<int> B(N);
	vector<int> S(N);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < N; i++)
		cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), cmp2);

	for (int i = 0; i < N; i++)
		S[i] = A[i] * B[i];

	cout << accumulate(S.begin(), S.end(), 0) << endl;

	return 0;
}