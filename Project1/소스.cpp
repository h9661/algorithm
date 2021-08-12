#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define ii pair<int, int>
using namespace std;

const int MAX = 300000;

int N, K;
int bag[MAX];
pair<int, int> jewelry[MAX];
priority_queue<int> pq;

int main() {
	fastio;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> jewelry[i].first >> jewelry[i].second;
	for (int i = 0; i < K; i++)
		cin >> bag[i];

	sort(jewelry, jewelry + N);
	sort(bag, bag + K);

	ll ans = 0;
	int idx = 0;

	for (int i = 0; i < K; i++) {
		while (idx < N && jewelry[idx].first <= bag[i])
			pq.push(jewelry[idx++].second);

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	
	cout << ans << endl;
}