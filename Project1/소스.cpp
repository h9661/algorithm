#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr(N, 0);
	vector<int> frequency(8001, 0);
	vector<int> max_frequency_arr;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr[i] = temp;
		frequency[temp + 4000]++;
	}
	int max_frequency = *max_element(frequency.begin(), frequency.end());
	for (int i = 0; i <= 8000; i++) {
		if (frequency[i] == max_frequency)
			max_frequency_arr.push_back(i - 4000);
	}

	sort(arr.begin(), arr.end());
	sort(max_frequency_arr.begin(), max_frequency_arr.end());
	max_frequency_arr.erase(unique(max_frequency_arr.begin(), max_frequency_arr.end()), max_frequency_arr.end());

	double average = floor(((double)accumulate(arr.begin(), arr.end(), 0) / N) + 0.5);
	int middle = arr[(N - 1) / 2];

	cout << average << endl;
	cout << middle << endl;
	if (max_frequency_arr.size() > 1)
		cout << max_frequency_arr[1] << endl;
	else
		cout << max_frequency_arr[0] << endl;
	cout << *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end()) << endl;

}