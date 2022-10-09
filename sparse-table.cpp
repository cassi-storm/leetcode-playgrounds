#include <bits/stdc++.h>
using namespace std;

class SparseTable {
public:
    vector<vector<int>> st;
    SparseTable(vector<int> &a) {
        int n = a.size();
        int m = 0, tp = n, x, s;
        while (tp) {
            ++m;
            tp >>= 1;
        }
        st = vector(m, vector(n, 0));
        for (int i = 0; i < n; ++i) {
            st[0][i] = a[i];
        }
        for (int i = 1; i < m; ++i) {
            s = 1 << (i - 1);
            x = n + 1 - (1 << i);
            for (int j = 0; j < x; ++j) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + s]);
            }
        }
    }
    int get(int l, int r) {
        int index = -1, v = 1, x = r - l + 1;
        for (;v <= x; ++index, v <<= 1);
        return min(st[index][l], st[index][r - v / 2 + 1]);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    SparseTable stable(a);
    for (auto row : stable.st) {
        for (auto v : row) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << stable.get(2, 10) << endl;
}
