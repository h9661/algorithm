#include <bits/stdc++.h>
#define endl '\n'
#define ii pair<int, int>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	set<int> st;
	int M;
	cin >> M;
	
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;

		if (s == "add") {
			int x;
			cin >> x;

			st.insert(x);
		}

		if (s == "remove") {
			int x;
			cin >> x;

			if (st.count(x) != 0) {
				st.erase(x);
			}
		}

		if (s == "check") {
			int x;
			cin >> x;

			if (st.count(x) != 0) {
				cout << 1 << endl;
			}
			else
				cout << 0 << endl;
		}

		if (s == "toggle") {
			int x;
			cin >> x;

			if (st.count(x) != 0)
				st.erase(x);
			else
				st.insert(x);
		}

		if (s == "all") {
			st = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,13,14,15,16,17,18,19,20 };
		}

		if (s == "empty")
			st.clear();
	}
}