#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> que1;
    queue<int> que2;

    for (int i = 0; i < queue1.size(); i++)
        que1.push(queue1[i]);

    for (int i = 0; i < queue2.size(); i++)
        que2.push(queue2[i]);

    long long sumOfQue1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long sumOfQue2 = accumulate(queue2.begin(), queue2.end(), 0);
    long long targetValue = (sumOfQue1 + sumOfQue2) / 2;
    int retval = 0;
    bool cantFindAnswer = false;

    while (true) {
        if (sumOfQue1 == targetValue)
            break;

        if (que1.size() + que2.size() + 100000 < retval) {
            cantFindAnswer = true;
            break;
        }

        if (sumOfQue1 < targetValue) {
            sumOfQue1 += que2.front();
            sumOfQue2 -= que2.front();

            que1.push(que2.front());
            que2.pop();
        }
        else if (sumOfQue1 > targetValue) {
            sumOfQue1 -= que1.front();
            sumOfQue2 += que1.front();

            que2.push(que1.front());
            que1.pop();
        }

        retval++;
    }

    if (cantFindAnswer == true)
        return -1;
    else
        return retval;
}