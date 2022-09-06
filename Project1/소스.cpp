#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr)
{
    deque<int> dq;

    for (int i = 0; i < arr.size(); i++) {
        if (dq.empty())
            dq.push_back(arr[i]);
        else {
            if (dq.back() != arr[i])
                dq.push_back(arr[i]);
            else
                continue;
        }
    }

    vector<int> answer;
    for (int i = 0; i < dq.size(); i++)
        answer.push_back(dq[i]);

    return answer;
}