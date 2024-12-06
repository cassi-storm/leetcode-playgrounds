#include <bits/stdc++.h>
using namespace std;

// gcd sparse table -- start
const int N = 2e5 + 10;
int S[20][N];
int A[N], B[N];
pair<int, int> Q[N];

void make_table(int n) {
    for (int i = 0; i < n; ++i) {
        S[0][i] = A[i];
    }
    for (int r = 1; r <= (int)log2(n); ++r) {
        int s = 1 << (r - 1);
        int ln = n - (1 << r) + 1;
        for (int i = 0; i < ln; ++i) {
            S[r][i] = __gcd(S[r - 1][i], S[r - 1][i + s]);
        }
    }
}

int get(int l, int r) {
    int d = r - l + 1;
    int index = (int)log2(d);
    return __gcd(S[index][l], S[index][r - (1 << index) + 1]);
}
// gcd sparse table -- end

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
