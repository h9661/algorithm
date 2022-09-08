#include <bits/stdc++.h>
using namespace std;

int maxValue = -10000;
vector<int> answer;

void ArrowComb(int count, int index, int n, vector<int>& comb, vector<int>& info, int& arrowN) {
    if (count == n) {
        vector<int> arrowArr(11, 0);
        int remainArrow = arrowN;

        for (int i = 0; i < 11; i++) {
            if (comb[i] == 1) {
                if (remainArrow > info[i]) {
                    arrowArr[i] = info[i] + 1;
                    remainArrow -= info[i] + 1;
                }
            }
            else
                continue;
        }

        if (remainArrow > 0) {
            arrowArr[10] += remainArrow;
            remainArrow = 0;
        }

        int lionScore = 0;
        int apeachScore = 0;

        for (int i = 0; i < 11; i++) {
            if (info[i] == 0 and arrowArr[i] == 0)
                continue;

            if (info[i] < arrowArr[i])
                lionScore += 10 - i;
            else
                apeachScore += 10 - i;
        }

        if (lionScore - apeachScore >= maxValue) {
            if (lionScore - apeachScore == maxValue) {
                for (int i = 10; i >= 0; i--) {
                    if (answer[i] < arrowArr[i]) {
                        answer = arrowArr;
                        break;
                    }
                    else if (answer[i] == arrowArr[i])
                        continue;
                    else
                        break;
                }
            }
            else {
                maxValue = lionScore - apeachScore;
                answer = arrowArr;
            }
        }

    }
    else {
        for (int i = index; i < 11; i++) {
            comb[i] = 1;

            ArrowComb(count + 1, index + 1, n, comb, info, arrowN);

            comb[i] = 0;
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    for (int i = 1; i <= n; i++) {
        vector<int> comb = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        ArrowComb(0, 0, i, comb, info, n);
    }

    if (maxValue <= 0)
        return { -1 };
    else
        return answer;
}