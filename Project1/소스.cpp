#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> retval;

    for (long long i = left; i <= right; i++) {
        int y = i / n;
        int x = i % n;

        retval.push_back(max(x + 1, y + 1));
    }

    return retval;
}