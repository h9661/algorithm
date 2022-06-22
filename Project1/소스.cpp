#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr(N);
	map<int, int> mp;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	vector<int> temp = arr;

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int i = 0; i < arr.size(); i++)
		mp[arr[i]] = i;

	for (int i = 0; i < temp.size(); i++)
		cout << mp[temp[i]] << " ";
}