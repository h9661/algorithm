#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 6385)
#pragma warning (disable : 6386)
#pragma warning (disable : 6200)
#pragma warning (disable : 26812)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int main() {
	fastio;
	queue<int> q;

	int N;
	cin >> N;

	while (N--) {
		string s;
		cin >> s;

		if (s == "push") {
			int k;
			cin >> k;
			q.push(k);
		}
		if (s == "pop") {
			if (q.empty())
				cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		if (s == "size")
			cout << q.size() << endl;
		if (s == "empty") {
			if (q.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		if (s == "front") {
			if (q.empty())
				cout << -1 << endl;
			else
				cout << q.front() << endl;
		}
		if (s == "back") {
			if (q.empty())
				cout << -1 << endl;
			else
				cout << q.back() << endl;
		}
	}
}