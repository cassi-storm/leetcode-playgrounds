#include <bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int> &stk, vector<bool> &vi, vector<vector<int>> &g) {
    if (vi[node]) return; 
    vi[node] = true;
    for (auto i : g[node]) {
        dfs(i, stk, vi, g);
    }
    stk.push(node);
}

void rdfs(int node, vector<bool> &vi, vector<vector<int>> &g) {
    if (vi[node]) return;
    vi[node] = true;
    for (auto i : g[node]) {
        rdfs(i, vi, g);
    }
}

int solve_kosaraju(int n, vector<vector<int>> &g, vector<vector<int>> &gi) {
    stack<int> stk;
    vector<bool> vi(n, false);
    for (int i = 0; i < n; ++i) {
        if (!vi[i]) {
            dfs(i, stk, vi, g);
        }
    }
    int count = 0;
    for (int i = 0; i < n; ++i) vi[i] = false;
    while (!stk.empty()) {
        int tp = stk.top();
        stk.pop();
        if (!vi[tp]) {
            ++count;
            rdfs(tp, vi, gi);
        }
    }
    return count;
}

int main() {
    int n, e;
    cin >> n >> e;
    int u, v;
    vector<vector<int>> g(n), gi(n);
    for (int i = 0; i < e; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        gi[v].push_back(u);
    }
    cout << "Components : " << solve_kosaraju(n, g, gi) << endl;
    return 0;
}

/**

7 9
0 1
1 2
2 0
2 3
3 4
4 5
5 3
5 6
3 6

*/
