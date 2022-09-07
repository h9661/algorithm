#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    int binaryTransCount = 0;
    int removedZeroCount = 0;

    while (s != "1") {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                removedZeroCount += 1;
        }

        while (s.find('0') != string::npos) {
            s.erase(s.begin() + s.find('0'));
        }

        int lenS = s.size();
        string newS = "";

        while (lenS != 0) {
            if (lenS % 2 == 0)
                newS += '0';
            else
                newS += '1';

            lenS /= 2;
        }

        reverse(newS.begin(), newS.end());
        s = newS;

        binaryTransCount += 1;
    }

    answer.push_back(binaryTransCount);
    answer.push_back(removedZeroCount);

    return answer;
}