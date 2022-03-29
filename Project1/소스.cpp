#include <bits/stdc++.h>
using namespace std;

void shiftLeft(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        arr[i] = arr[i + 1];
        arr[i + 1] = 0;
    }
}

bool isEmpty(vector<int> arr) {
    bool check = true;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            check = false;
            break;
        }
    }

    return check;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    vector<int> arr(bridge_length + 1, 0);

    queue<int> q;
    for (int i = 0; i < truck_weights.size(); i++)
        q.push(truck_weights[i]);

    int curWeight = 0;

    while (1) {

        if (!q.empty()) {
            if (curWeight + q.front() <= weight) {
                curWeight += q.front();
                arr[bridge_length] = q.front();

                q.pop();
            }
        }

        shiftLeft(arr);
        time++;

        if (arr[0] != 0) {
            curWeight -= arr[0];
            arr[0] = 0;
        }

        if (isEmpty(arr) && q.empty())
            break;
    }

    return time + 1;
}

int main() {
    vector<int> arr = { 7, 4, 5, 6 };
    cout << solution(2, 10, arr) << endl;
}