#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s) {
	stringstream ss;
	ss.str(s);
	vector<string> retval;
	string temp;

	while (ss >> temp)
		retval.push_back(temp);

	return retval;
}

vector<int> solution(vector<int> fees, vector<string> records) {
	map<int, vector<vector<int>>> recorder;
	map<int, int> feeRecorder;

	for (int i = 0; i < records.size(); i++) {
		vector<string> record = split(records[i]);
		string time = record[0];
		int number = stoi(record[1]);
		string direction = record[2];

		int h = stoi(time.substr(0, 2));
		int m = stoi(time.substr(3, 5));
		int nTime = h * 60 + m;

		if (direction == "IN")
			recorder[number].push_back({ nTime, 0 });
		else
			recorder[number].push_back({ nTime, 1 });
	}

	for (map<int, vector<vector<int>>>::iterator iter = recorder.begin(); iter != recorder.end(); iter++) {
		int number = iter->first;
		vector<vector<int>> infos = iter->second;

		int in_t = -999;
		int out_t = -999;
		int fee = fees[1];
		int parking_t = out_t - in_t;

		if (infos.size() % 2 != 0)
			infos.push_back({ 23 * 60 + 59, 1 });

		for (int i = 0; i < infos.size(); i++) {
			int t = infos[i][0];
			int d = infos[i][1];

			if (d == 0)
				in_t = t;
			else
				out_t = t;

			if (in_t < out_t)
				parking_t += out_t - in_t;
		}

		parking_t -= fees[0];

		if (parking_t > 0) {
			if (parking_t % fees[2] == 0)
				fee += (parking_t / fees[2]) * fees[3];
			else
				fee += ((parking_t / fees[2]) + 1) * fees[3];
		}

		feeRecorder[number] = fee;
	}

	vector<int> retval;

	for (map<int, int>::iterator iter = feeRecorder.begin(); iter != feeRecorder.end(); iter++) {
		retval.push_back(iter->second);
	}

	return retval;
}