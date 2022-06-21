#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

vector<string> split(string str, char token) {
	vector<string> retval;
	
	if (str == "")
		return retval;

	if (str.size() == 1) {
		retval.push_back(str);
		return retval;
	}

	int start = 0;
	int d = str.find(token);

	while (d != -1) {
		retval.push_back(str.substr(start, d - start));
		start = d + 1;
		d = str.find(token, start);
	}
	retval.push_back(str.substr(start, d - start));

	return retval;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;

	while (t--) {
		string op;
		cin >> op;

		int n;
		cin >> n;

		string temp;
		cin >> temp;
		temp.pop_back();
		temp.erase(temp.begin());

		vector<string> temparr = split(temp, ',');

		deque<string> arr;
		for (int i = 0; i < temparr.size(); i++)
			arr.push_back(temparr[i]);

		bool f = true;
		bool contFlag = false;
		for (int i = 0; i < op.size(); i++) {
			if (op[i] == 'R')
				f = !f;

			if (op[i] == 'D') {
				if (arr.size() == 0) {
					cout << "error" << endl;
					contFlag = true;
					break;
				}
				else {
					if (f == true)
						arr.pop_front();
					else
						arr.pop_back();
				}
			}
		}

		if (contFlag)
			continue;

		if (arr.size() == 0) {
			cout << "[]";
		}
		else {
			if (f == true) {
				cout << '[';
				for (int i = 0; i < arr.size() - 1; i++)
					cout << arr[i] << ",";
				cout << arr[arr.size() - 1] << ']';
			}
			else {
				cout << '[';
				for (int i = arr.size() - 1; i >= 1; i--)
					cout << arr[i] << ",";
				cout << arr[0] << ']';
			}
		}
		cout << endl;
	}
}