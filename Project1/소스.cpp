#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, char delimiter) {
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter))
		answer.push_back(temp);

	return answer;
}

bool isPrime(long long n) {
	if (n == 1)
		return false;

	for (int i = 2; i < int(sqrt(n)) + 1; i++) {
		if (n % i == 0)
			return false;
	}

	return true;
}

int solution(int n, int k) {
	int retval = 0;
	string answer = "";

	while (n > 0) {
		answer += to_string(n % k);
		n /= k;
	}

	reverse(answer.begin(), answer.end());

	vector<string> lst = split(answer, '0');

	for (int i = 0; i < lst.size(); i++) {
		if (lst[i].size() == 0)
			continue;

		if (isPrime(stoll(lst[i])) == true)
			retval += 1;
	}

	return retval;
}