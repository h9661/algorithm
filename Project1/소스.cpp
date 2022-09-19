#include <bits/stdc++.h>

using namespace std;

vector<int> ansVec;
vector<bool> check(9, false);
int g_count = 0;

void dfs(vector<vector<int>> dungeons, int k) {
    for (int i = 0; i < dungeons.size(); i++) {
        if (check[i] == false) {
            check[i] = true;

            int minCost = dungeons[i][0];
            int useCost = dungeons[i][1];

            if (minCost <= k) {
                k -= useCost;
                g_count++;

                dfs(dungeons, k);
                ansVec.push_back(g_count);

                g_count--;
                k += useCost;
            }

            check[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    ansVec.clear();
    check.clear();
    g_count = 0;


    dfs(dungeons, k);

    return *max_element(ansVec.begin(), ansVec.end());
}