#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n, tn;
    vector<int> v;
    vector<int> a;
    void build(int index, int st, int en) {
        if (st == en) {
            a[index] = v[st];
            return;
        }
        int mid = st + (en - st) / 2;
        build(2 * index, st, mid);
        build(2 * index + 1, mid + 1, en);
        a[index] = a[2 * index] + a[2 * index + 1];
    }
    int get(int index, int st, int en, int l, int r) {
        if (st > r || en < l) 
            return 0;
        if (l <= st && en <= r) 
            return a[index];
        int mid = st + (en - st) / 2;
        return get(2 * index, st, mid, l, r) + get(2 * index + 1, mid + 1, en, l, r);
    }
    void put(int index, int x, int st, int en, int i) {
        if (st > i || en < i) 
            return;
        a[index] += x;
        if (st == en) 
            return;
        int mid = st + (en - st) / 2;
        mid >= i ? put(2 * index, x, st, mid, i) : put(2 * index + 1, x, mid + 1, en, i);
    }
public:
    SegmentTree() {
        n = tn = 0;
    }
    SegmentTree(int size) {
        n = size;
        a = vector<int> (tn = 4 * n, 0);
    }
    void build(vector<int>& t) {
        v = t;
        n = v.size();
        a = vector<int> (tn = 4 * n, 0);
        build(1, 0, n - 1);
    }
    int get(int l, int r) {
        if (l > r || r < 0 || l >= n) {
            return 0;
        }
        l = max(l, 0);
        r = min(r, n - 1);
        return get(1, 0, n - 1, l, r);
    }
    void put(int val, int index) {
        if (index < 0 || n <= index) 
            return;
        int x = val - v[index];
        v[index] += x;
        put(1, x, 0, n - 1, index);
    }
    void print() {
        for (auto i : a) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> a(10);
    for (int i = 0; i < 10; ++i) {
        a[i] = i + 1;
    }
    SegmentTree tree;
    tree.build(a);
    // tree.print();
    cout << tree.get(0, 9) << endl;
    cout << tree.get(0, 3) << endl;
    cout << tree.get(3, 4) << endl;
    cout << tree.get(4, 4) << endl;
    cout << tree.get(7, 9) << endl;
    cout << endl << endl;
    tree.put(7, 7);
    cout << tree.get(0, 9) << endl;
    cout << tree.get(0, 3) << endl;
    cout << tree.get(3, 4) << endl;
    cout << tree.get(4, 4) << endl;
    cout << tree.get(7, 9) << endl;
    return 0;
}
