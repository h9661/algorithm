#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int>> dq;

    for (int i = 0; i < priorities.size(); i++) {
        dq.push_back({ i, priorities[i] });
    }

    int target_index = location;

    while (1) {
        pair<int, int> max_value = *max_element(dq.begin(), dq.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
            });

        if (dq.front().second == max_value.second) {
            answer++;

            if (dq.front().first == target_index)
                break;

            dq.pop_front();
        }
        else {
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }

    return answer;
}