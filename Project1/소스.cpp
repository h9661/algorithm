#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

struct point {
	int weight, position, id;
};

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<point> points(m);
	for (int i = 0; i < m; i++) {
		cin >> points[i].position >> points[i].weight;
		points[i].id = i + 1;
	}

	sort(points.begin(), points.end(), [](point a, point b) {
		return a.weight < b.weight;
		}
	);

	int sum = 0;
	
	for (int i = 0; i < m; i++) {
		if (i < 2 * n)
			sum += points[i].weight;
		else
			points.pop_back();
	}

	sort(points.begin(), points.end(), [](point a, point b) {
		return a.position < b.position;
		}
	);

	cout << sum << endl;
	for (int i = 0; i < n; i++)
		cout << points[i].id << ' ' << points[2 * n - i - 1].id << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}