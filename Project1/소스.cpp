#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	int M;
	cin >> M;

	string s;
	cin >> s;

	int count = 0;

	for (int i = 0; i < M; i++) {
		int k = 0;

		if (s[i] == 'O')
			continue;
		else {
			while (s[i + 1] == 'O' && s[i + 2] == 'I') {
				k++;
				if (k == N) {
					k--;
					count++;
				}
				
				i += 2;
			}

			k = 0;
		}
	}

	cout << count << endl;
}