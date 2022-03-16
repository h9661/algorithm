#include <bits/stdc++.h>
using namespace std;

string str;
int ans = 0;
map<int, bool> mp;

void dfs(string numbers, vector<bool>& check) {
    if (str.size() > 0) {
        int num = stoi(str);
        bool isPrime = true;

        if (mp[num] == false)
            mp[num] = true;
        else
            isPrime = false;

        if (num < 2)
            isPrime = false;

        for (int i = 2; i <= num - 1; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            ans++;
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (check[i] == false) {
            check[i] = true;
            str.push_back(numbers[i]);

            dfs(numbers, check);

            check[i] = false;
            str.pop_back();
        }
    }
}

int solution(string numbers) {
    vector<bool> check(numbers.size(), false);

    dfs(numbers, check);

    return ans;
}