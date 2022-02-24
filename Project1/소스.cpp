#include <bits/stdc++.h>
using namespace std;

int g_count[8010];

int main() {
	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		g_count[4000 + a[i]]++;
	}

	int k = 0;
	for (int i = 0; i <= 8000; i++) {
		if (k < g_count[i])
			k = g_count[i];
	}
	bool check = false;

	int z = 0;
	for (int i = 0; i <= 8000; i++) {
		if (g_count[i] == k) {
			z = i - 4000;

			if (check == true)
				break;

			check = true;
		}
	}


	sort(a.begin(), a.end());
	if (round(accumulate(a.begin(), a.end(), 0) / (double)a.size()) == -0)
		cout << 0 << endl;
	else
		cout << round(accumulate(a.begin(), a.end(), 0) / (double)a.size()) << endl;
	cout << a[a.size() / 2] << endl;
	cout << z << endl;
	cout << a[a.size() - 1] - a[0] << endl;
}