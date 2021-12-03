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

int k;
vector<char> arr;
char selects[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
bool check[10];
string temp;
vector<string> result;

void backtracking(int count) {
	if (count == k + 1) {
		for (int i = 0; i < k; i++) {
			if (arr[i] == '<') {
				if (temp[i] > temp[i + 1])
					return;
			}
			if (arr[i] == '>') {
				if (temp[i] < temp[i + 1])
					return;
			}
		}
		result.push_back(temp);
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (check[i] == false) {
				check[i] = true;
				
				temp.push_back(i + '0');
				backtracking(count + 1);
				temp.pop_back();

				check[i] = false;
			}
		}
	}
}

int main() {
	fastio;
	cin >> k;


	for (int i = 0; i < k; i++) {
		char temp;
		cin >> temp;
		arr.push_back(temp);
	}

	backtracking(0);

	sort(result.begin(), result.end());

	cout << result.at(result.size() - 1) << endl;
	cout << result.at(0) << endl;

	return 0;
}