#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin >> tc;
	while (tc--) {
		vector<bool> check(10001, false);
		queue<pair<int, string>> q;
		int cur, target;
		cin >> cur >> target;

		q.push({ cur, "" });
		check[cur] = true;

		string ans = "2432432423423232323232323232323323";

		while (!q.empty()) {
			int curPos = q.front().first;
			string curOp = q.front().second;
			//cout << curPos << " " << curOp << endl;
			q.pop();

			if (curPos == target) {
				if (ans.size() >= curOp.size())
					ans = curOp;
				break;
			}

			//D
			int nxtPos = (curPos * 2) % 10000;
			if (check[nxtPos] == false) {
				q.push({ nxtPos, curOp + "D" });
				check[nxtPos] = true;
			}

			//S
			nxtPos = curPos - 1 < 0 ? 9999 : curPos - 1;
			if (check[nxtPos] == false) {
				q.push({ nxtPos, curOp + "S" });
				check[nxtPos] = true;
			}

			//L
			string temp = to_string(curPos);
			if (temp.size() < 4) {
				for (int i = 0; i < 4 - temp.size(); i++)
					temp.insert(temp.begin(), '0');
			}
			char strtemp = temp[0];
			for (int i = 0; i < temp.size() - 1; i++) {
				temp[i] = temp[i + 1];
			}
			temp[temp.size() - 1] = strtemp;
			nxtPos = stoi(temp);
			if (check[nxtPos] == false) {
				q.push({ nxtPos, curOp + "L" });
				check[nxtPos] = true;
			}

			//R
			temp = to_string(curPos);
			if (temp.size() < 4) {
				for (int i = 0; i < 4 - temp.size(); i++)
					temp.insert(temp.begin(), '0');
			}
			char strTemp = temp[temp.size() - 1];
			for (int i = temp.size() - 1; i >= 1; i--) {
				temp[i] = temp[i - 1];
			}
			temp[0] = strTemp;
			nxtPos = stoi(temp);
			if (check[nxtPos] == false) {
				q.push({ nxtPos, curOp + "R" });
				check[nxtPos] = true;
			}

		}
		cout << ans << endl;
	}
}