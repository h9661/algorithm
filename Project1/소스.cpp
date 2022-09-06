#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> sizes) {
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] < sizes[i][1])
            swap(sizes[i][0], sizes[i][1]);
    }

    int row = 0;
    int col = 0;

    for (int i = 0; i < sizes.size(); i++) {
        row = max(row, sizes[i][0]);
        col = max(col, sizes[i][1]);
    }

    return row * col;
}