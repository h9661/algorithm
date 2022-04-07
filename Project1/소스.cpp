#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    string answer = "";

    vector<char> st;

    for (auto i : number) {
        while (!st.empty() && st.back() < i && k > 0) {
            st.pop_back();
            k -= 1;
        }

        st.push_back(i);
    }

    while (k > 0) {
        st.pop_back();
        k -= 1;
    }

    for (auto i : st)
        answer += i;


    return answer;
}