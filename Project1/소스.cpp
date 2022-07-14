#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

vector<int> arr(4000001);

void eratos() {
	for (int i = 2; i <= 4000000; i++)
		arr[i] = i;

	for (int i = 2; i <= 4000000; i++) {
		if (arr[i] == 0)
			continue;

		for (int j = 2 * i; j <= 4000000; j += i)
			arr[j] = 0;
	}
}

int main() {
	eratos();
	
	int N;
	cin >> N;

	int left = N;
	int right = N;

	int count = 0;

	while (left <= right and left >= 0) {
		if (arr[left] == 0) {
			left--;
			continue;
		}
		if (arr[right] == 0) {
			right--;
			continue;
		}

		/*cout << left << " " << right << endl;
		cout << arr[left] << " " << arr[right] << endl;*/

		int sum = accumulate(arr.begin() + left, arr.begin() + right + 1, 0);
		/*cout << sum << endl;*/
		
		if (sum <= N) {
			left--;

			if (sum == N)
				count++;
		}
		else
			right--;
	}

	cout << count << endl;
}