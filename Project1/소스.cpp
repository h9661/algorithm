#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, string>> members;
	for (int i = 0; i < n; i++) {
		int age; string name;
		cin >> age >> name;

		members.push_back({ age, name });
	}

	stable_sort(members.begin(), members.end(), [](pair<int, string> a, pair<int, string> b) {
		return a.first < b.first;
		}
	);

	for (auto& i : members)
		cout << i.first << " " << i.second << endl;	
}