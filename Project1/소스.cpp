#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int result = 0;
vector<int> result_vec;

vector<int> makeTable(const string& p) {
	vector<int> table(p.size(), 0);

	int j = 0;
	for (int i = 1; i < p.size(); i++) {
		while (j > 0 && p[i] != p[j])
			j = table[j - 1];

		if (p[i] == p[j])
			table[i] = ++j;
	}

	return table;
}

void kmp(const string& t, const string& p) {
	vector<int> table = makeTable(p);

	int j = 0;
	for (int i = 0; i < t.size(); i++) {
		while (j > 0 && t[i] != p[j])
			j = table[j - 1];

		if (t[i] == p[j]) {
			if (j == p.size() - 1) {
				result_vec.push_back(i - p.size() + 2);
				j = table[j];
				result++;
			}
			else
				j++;
		}
	}
}

int main() {
	string p;
	cin >> p;

	int maxValue = 0;

	for (int i = 0; i < p.size(); i++) {
		vector<int> table = makeTable(p.substr(i, string::npos));
		
		int value = *max_element(table.begin(), table.end());

		if (value > maxValue)
			maxValue = value;
	}

	cout << maxValue << endl;

	return 0;
}