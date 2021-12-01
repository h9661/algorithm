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
	int N;
	cin >> N;
	vector<string> strArr;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		
		strArr.push_back(temp);
	}

	string ans;

	for (int i = 0; i < strArr[0].size(); i++) {
		bool flag = true;

		for (int j = 0; j < strArr.size() - 1; j++) {
			if (strArr[j][i] == strArr[j + 1][i]) {
				continue;
			}
			else {
				flag = false;
				break;
			}
		}

		if (flag)
			ans.push_back(strArr[0][i]);
		else
			ans.push_back('?');
	}

	cout << ans << endl;
}