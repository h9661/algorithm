#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long int
#define ui unsigned int
#define endl '\n'
#define fastio (cin.tie(NULL), cout.sync_with_stdio(false), cout.tie(NULL))
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int INF = 987654321;
const int MAXN = 52;
int pipe_num;
int capacity[MAXN][MAXN], flow[MAXN][MAXN];
int parent[MAXN];
vector<int> graph[MAXN];

int MaximumFlow(int source, int sink) {
    memset(flow, 0, sizeof(flow));
    int total_flow = 0;

    while (1) {
        fill(parent, parent + MAXN, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int i = 0; i < graph[x].size(); i++) {
                int y = graph[x][i];

                if (capacity[x][y] - flow[x][y] > 0 && parent[y] == -1) {
                    q.push(y);
                    parent[y] = x;

                    if (y == sink)
                        break;
                }
            }
        }

        if (parent[sink] == -1)
            break;

        int amount = INF;
        for (int p = sink; p != source; p = parent[p])
            amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);

        for (int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }

        total_flow += amount;
    }

    return total_flow;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> pipe_num;

    memset(capacity, 0, sizeof(capacity));
    char u, v;
    int pipe_cap;
    for (int i = 0; i < pipe_num; ++i) {
        cin >> u >> v >> pipe_cap;

        if (u > 90)
            u = u - 'a' + 26;
        else
            u = u - 'A';

        if (v > 90)
            v = v - 'a' + 26;
        else
            v = v - 'A';

        graph[u].push_back(v);
        graph[v].push_back(u);

        capacity[u][v] += pipe_cap;
        capacity[v][u] += pipe_cap;
    }

    cout << MaximumFlow('A' - 'A', 'Z' - 'A') << "\n";
    return 0;
}