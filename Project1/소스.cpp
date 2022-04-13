#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> graph[], int startloc, const int n, vector<bool>& check) {
    queue<int> q;

    q.push(startloc);
    check[startloc] = true;

    while (!q.empty()) {
        int curNode = q.front();
        q.pop();

        for (int i = 0; i < graph[curNode].size(); i++) {
            int nextNode = graph[curNode][i];

            if (check[nextNode] == false) {
                check[nextNode] = true;
                q.push(nextNode);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<bool> check(n, false);
    vector<int> graph[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (computers[i][j] == 1) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (check[i] == false) {
            bfs(graph, i, n, check);
            answer++;
        }
    }


    return answer;
}