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

const int MAX = 16;
int L, C;
char arr[MAX];
bool check[MAX];
string str(L, NULL);
vector<string> ans;

void backtracking(int count, int a, int b, int idx) {
	if (count == L and a >= 1 and b >= 2) {
		ans.push_back(str);
	}
	else {
		for (int i = idx; i < C; i++) {
			if (check[i] == false) {
				check[i] = true;

				str.push_back(arr[i]);
				if (arr[i] == 'a' or arr[i] == 'e' or arr[i] == 'i' or arr[i] == 'o' or arr[i] == 'u')
					backtracking(count + 1, a + 1, b, i + 1);
				else
					backtracking(count + 1, a, b + 1, i + 1);
				str.pop_back();

				check[i] = false;
			}
		}
	}
}

int main() {
	fastio;
	cin >> L >> C;

	for (int i = 0; i < C; i++)
		cin >> arr[i];

	sort(arr, arr + C);
	backtracking(0, 0, 0, 0);
	
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;

	return 0;
}