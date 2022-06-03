#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	map<string, string> poket;

	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;

		poket[s] = to_string(i);
		poket[to_string(i)] = s;
	}

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;

		cout << poket[s] << endl;
	}
}