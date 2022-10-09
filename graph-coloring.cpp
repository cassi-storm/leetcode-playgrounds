#include <bits/stdc++.h>
using namespace std;

void topological_sort(int node, vector<vector<int>> &g, vector<int> &a, vector<int> &v) {
    if (v[node] == 1) {
        return;
    }
    v[node] = 1;
    a.push_back(node);
    if (g[node].size() == 0) return;
    for (auto i : g[node]) {
        topological_sort(i, g, a, v);    
    }
} 

int get_number_of_ways(vector<vector<int>> &g, vector<int> &a, vector<int> &c, int cr, int n) {
    if (cr == n) {
        return 1;
    }
    int node = a[cr];
    if (g[node].size() == 0) return 3;
    vector<int> colors(4, 0);
    for (auto i : g[node]) {
        colors[c[i]] = 1;
    }
    int sumi = 0;
    for (int i = 1; i < 4; ++i) {
        if (colors[i] == 0) {
            c[node] = i;
            sumi += get_number_of_ways(g, a, c, cr + 1, n);
        }
    }
    c[node] = 0;
    return sumi;
}

int graph_coloring(vector<vector<int>> &g, int n) {
    vector<int> color(n, 0), visited(n, 0), arr;
    int result = 1;
    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0) {
            topological_sort(i, g, arr, visited);
            result *= get_number_of_ways(g, arr, color, 0, arr.size());
            arr.clear();
        }
    }
    return result;
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << graph_coloring(g, n) << endl;
    return 0;
}

/*

5 5
1 2 
1 4
1 5
5 3
5 4

3 3
3 1
2 3
1 2

2 0

*/
