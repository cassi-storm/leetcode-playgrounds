#include <bits/stdc++.h>
using namespace std;

class LazySegmentTree {
private:
    int n;
    vector<int> a, tree, lazy;
    void build(int node, int s, int e) {
        if (s == e) {
            tree[node] = a[s];
            return;
        }
        int m = s + (e - s) / 2;
        build(2 * node, s, m);
        build(2 * node + 1, m + 1, e);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void put(int node, int l, int r, int s, int e, int x) {
        if (l > e || r < s) return;
        if (l <= s && e <= r) {
            if (s != e) {
                lazy[2 * node] += x;
                lazy[2 * node + 1] += x;
            }
            tree[node] += (e - s + 1) * x;
            return;
        }
        int m = s + (e - s) / 2;
        put(2 * node, l, r, s, m, x);
        put(2 * node + 1, l, r, m + 1, e, x);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    int get(int node, int l, int r, int s, int e) {
        if (l > e || r < s) return 0;
        if (l <= s && e <= r) {
            if (lazy[node]) {
                if (s != e) {
                    lazy[2 * node] += lazy[node];
                    lazy[2 * node + 1] += lazy[node];
                }
                tree[node] += (e - s + 1) * lazy[node];
                lazy[node] = 0;
            }
            return tree[node];
        }
        int m = s + (e - s) / 2;
        return get(2 * node, l, r, s, m) + get(2 * node + 1, l, r, m + 1, e);
    }
public:
    LazySegmentTree() {}
    LazySegmentTree(int n) {
        a = vector<int> (n, 0);
        tree = vector<int> (n * 4, 0);
        lazy = vector<int> (n * 4, 0);
    }
    LazySegmentTree(vector<int>& v) {
        build(v);
    }
    void build(vector<int>& v) {
        n = v.size();
        a = v;
        tree = vector<int> (n * 4, 0);
        lazy = vector<int> (n * 4, 0);
        build(1, 0, n - 1);
    }
    void put(int l, int r, int x) {
        put(1, l, r, 0, n - 1, x);
    }
    int get(int l, int r) {
        if (l > r || r < 0 || l >= n) return 0;
        l = max(l, 0);
        r = min(r, n - 1);
        return get(1, l, r, 0, n - 1);
    }
    void print() {
        cout << endl << "Tree : ";
        for (auto i : tree) {
            printf("%2d ", i);
        }
        cout << endl;
        cout << "Lazy : ";
        for (auto i : lazy) {
            printf("%2d ", i);
        }
        cout << endl << endl;;
    }
};

int main() {
    vector<int> a(10);
    for (int i = 0; i < 10; ++i) {
        a[i] = i + 1;
    }
    LazySegmentTree tree;
    tree.build(a);
    tree.print();
    cout << tree.get(0, 9) << endl;
    cout << tree.get(0, 4) << endl;
    cout << tree.get(5, 9) << endl;
    cout << tree.get(2, 3) << endl;
    cout << tree.get(7, 9) << endl;
    cout << tree.get(1, 9) << endl;
    cout << tree.get(6, 9) << endl;
    tree.put(4, 9, 2);
    tree.print();
    cout << tree.get(0, 9) << endl;
    cout << tree.get(6, 9) << endl;
    tree.print();
    return 0;
}
