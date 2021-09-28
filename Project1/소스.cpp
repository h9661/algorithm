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

string P, T;
int result = 0;
vector<int> result_vec;

vector<int> makeTable(const string& pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);

	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = table[j - 1];

		if (pattern[i] == pattern[j])
			table[i] = ++j;
	}

	return table;
}

void kmp(const string& text, const string& pattern) {
	vector<int> table = makeTable(pattern);

	int textSize = text.size();
	int patternSize = pattern.size();

	int j = 0;
	for (int i = 0; i < textSize; i++) {
		while (j > 0 && text[i] != pattern[j])
			j = table[j - 1];

		if (text[i] == pattern[j]) {
			if (j == patternSize - 1) {
				result_vec.push_back(i - patternSize + 2);
				j = table[j];
				result++;
			}
			else
				j++;
		}
	}
}

int main() {
	getline(cin, T);
	getline(cin, P);

	kmp(T, P);

	cout << result << endl;
	for (int i = 0; i < result_vec.size(); i++)
		cout << result_vec[i] << " ";

	return 0;
}