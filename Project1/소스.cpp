#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int main() {
	list<char> lst;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
		lst.push_back(str[i]);

	int n;
	cin >> n;


	auto pointer = lst.end();
	for (int i = 0; i < n; i++) {

		char a;
		cin >> a;

		if (a == 'L') {
			if (pointer == lst.begin())
				continue;
			else
				pointer--;
		}
		else if (a == 'D') {
			if (pointer == lst.end())
				continue;
			else
				pointer++;
		}
		else if (a == 'B') {
			if (pointer == lst.begin())
				continue;
			else {
				pointer = lst.erase(--pointer);
			}
		}
		else if (a == 'P') {
			char temp;
			cin >> temp;

			lst.insert(pointer, temp);
		}
	}

	for (auto i : lst)
		cout << i;

	return 0;
}