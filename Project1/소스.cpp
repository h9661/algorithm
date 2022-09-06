#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    map<char, int> scorer;

    for (int i = 0; i < choices.size(); i++) {
        if (choices[i] > 4) {
            scorer[survey[i][1]] += choices[i] - 4;
        }
        if (choices[i] < 4) {
            scorer[survey[i][0]] += 4 - choices[i];
        }
    }

    string answer = "";

    vector<string> arr = { "RT", "CF", "JM", "AN" };
    for (int i = 0; i < arr.size(); i++) {
        if (scorer[arr[i][0]] < scorer[arr[i][1]])
            answer.push_back(arr[i][1]);
        if (scorer[arr[i][0]] > scorer[arr[i][1]])
            answer.push_back(arr[i][0]);

        if (scorer[arr[i][0]] == scorer[arr[i][1]]) {
            string temp = arr[i];
            sort(temp.begin(), temp.end());
            answer.push_back(temp[0]);
        }
    }

    return answer;
}