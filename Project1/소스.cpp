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

int main() {
	string S;
	cin >> S;

	vector<string> subStr;

	for (int i = 0; i < S.size(); i++) {
		string temp = S.substr(i);

		subStr.push_back(temp);
	}

	sort(subStr.begin(), subStr.end());

	for (int i = 0; i < subStr.size(); i++)
		cout << subStr[i] << endl;
}