#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	queue<int> q;
	vector<int> store;
	int count = 1;

	for (int i = 1; i <= N; i++)
		q.push(i);

	while (!q.empty()) {
		if (count == K) {
			store.push_back(q.front());
			q.pop();
			count = 1;
		}
		else {
			q.push(q.front());
			q.pop();
			count++;
		}
	}


	cout << "<";
	for (int i = 0; i < store.size() - 1; i++)
		cout << store[i] << ", ";
	cout << store[store.size() - 1] << ">";

	return 0;

}