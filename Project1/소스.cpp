#include <bits/stdc++.h>
#define endl '\n'
#define ll pair<long long, long long>
#define ii pair<int, int>
using namespace std;

int N;
bool visited[30];
bool flag_a[100];
bool flag_b[100];
int ans = 0;

void dfs(int count) {
	if (count == N) {
		ans++;
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (!visited[i] and !flag_a[i + count] and !flag_b[i - count + 7]) {
				visited[i] = true;
				flag_a[i + count] = true;
				flag_b[i - count + 7] = true;

				dfs(count + 1);

				visited[i] = false;
				flag_a[i + count] = false;
				flag_b[i - count + 7] = false;
			}
		}
	}
}

int main() {
	cin >> N;
	dfs(0);
	cout << ans << endl;
}