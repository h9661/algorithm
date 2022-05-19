#include <bits/stdc++.h>
using namespace std;

int main() {
	while (1) {
		string str = "";
		cin >> str;
		string temp = str;
		if (str == "0")
			break;

		reverse(str.begin(), str.end());
		if (temp == str)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}