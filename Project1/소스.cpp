#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int count = 0;

	vector<int> multitap(K);
	for (int i = 0; i < K; i++)
		cin >> multitap[i];

	vector<int> plug;

	for (int i = 0; i < K; i++) {
		if (find(plug.begin(), plug.end(), multitap[i]) != plug.end())
			continue;

		if (plug.size() < N) {
			plug.push_back(multitap[i]);
			continue;
		}

		vector<int> multitap_Idxs;
		int multitap_idx = 0;
		bool cont_flag = true;

		for (int j = 0; j < N; j++) {
			if (find(multitap.begin() + i, multitap.end(), plug[j]) != multitap.end())
				multitap_idx = find(multitap.begin() + i, multitap.end(), plug[j]) - (multitap.begin() + i);
			else {
				multitap_idx = 101;
				cont_flag = false;
			}

			multitap_Idxs.push_back(multitap_idx);

			if (!cont_flag)
				break;
		}

		int plugOut_idx = find(multitap_Idxs.begin(), multitap_Idxs.end(),
			*max_element(multitap_Idxs.begin(), multitap_Idxs.end())) - multitap_Idxs.begin();
		plug.erase(plug.begin() + plugOut_idx);
		plug.push_back(multitap[i]);
		count++;
	}

	cout << count << endl;
} 