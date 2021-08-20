#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int MAX = 500000 + 1;
int N, M;
int arr1[MAX];
int arr2[MAX];

int main() {
	fastio;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr1[i];

	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> arr2[i];

	sort(arr1, arr1 + N);

	int count = 0;

	for (int i = 0; i < M; i++) {
		int start = 0;
		int end = N;
		bool flag = false;

		while (start <= end) {
			int mid = (start + end) / 2;

			if (arr1[mid] < arr2[i])
				start = mid + 1;
			else if(arr1[mid] >= arr2[i])
				end = mid - 1;

			if (arr1[mid] == arr2[i])
				flag = true;
		}
		if (flag)
			cout << "1" << " ";
		else
			cout << "0" << " ";
	}

	return 0;
}