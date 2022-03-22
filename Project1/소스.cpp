#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, pair<bool, int>> mp;

    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = 0; j < phone_book[i].size(); j++) {
            mp[phone_book[i].substr(0, j)] = { true, i };
        }
    }

    for (int i = 0; i < phone_book.size(); i++) {
        if (mp[phone_book[i]].first == true && mp[phone_book[i]].second != i) {
            answer = false;
            break;
        }
    }

    return answer;
}