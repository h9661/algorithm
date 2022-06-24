#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

struct cmp {
	bool operator()(ii a, ii b) {
		if (a.first != b.first)
			return a.first > b.first;
		else
			return a.second > b.second;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	priority_queue<ii, vector<ii>, cmp> pq;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		if (x != 0)
			pq.push({ abs(x), x });

		if (x == 0) {
			if(pq.size() == 0)
				cout << 0 << endl;
			else {
				cout << pq.top().second << endl;
				pq.pop();
			}
		}
	}
}