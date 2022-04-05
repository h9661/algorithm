#include <bits/stdc++.h>
using namespace std;

int coefficient[26];

int main() {
	int n;
	cin >> n;

	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		int level = pow(10, arr[i].size());

		for (int j = 0; j < arr[i].size(); j++) {
			coefficient[arr[i][j] - 'A'] += level;
			level /= 10;
		}
	}

	vector<pair<char, int>> countArr;
	for (int i = 0; i < 26; i++) {
		if (coefficient[i] != 0) {
			countArr.push_back({ i + 'A' , coefficient[i] });
		}
	}

	sort(countArr.begin(), countArr.end(), [](pair<char, int> a, pair<char, int> b){
		return a.second > b.second;
		});

	map<char, int> mp;

	int k = 9;
	for (int i = 0; i < countArr.size(); i++) {
		mp[countArr[i].first] = k--;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			arr[i][j] = mp[arr[i][j]] + '0';
		}
	}
	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
		sum += stoi(arr[i]);

	cout << sum << endl;
}