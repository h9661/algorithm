#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int A, B, V;
	cin >> A >> B >> V;

	int answer = 0;
	answer += (V - A) / (A - B);
	answer += 1;

	if (((V - A) % (A - B)) != 0)
		answer += 1;

	cout << answer << endl;
}