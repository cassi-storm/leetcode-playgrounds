class FenwickTree {
public:
    int n;
    vector<int> a;
    FenwickTree(int x): n(x), a(n, 0) {}
    void put(int x, int v) {
        for (; x < n; x |= x + 1) {
            a[x] += v;
        }
    }
    int get(int x) {
        if (x < 0) return 0;
        int sum_ = 0;
        for (; x >= 0; x = (x & (x + 1)) - 1) {
            sum_ += a[x];
        }
        return sum_;
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> p(n), r(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    p[a[0].second] = 0;
    for (int i = 1; i < n; ++i) {
        p[a[i].second] = i;
        r[a[i].second] = a[i].first == a[i - 1].first ? r[a[i - 1].second] : i;
    }
    FenwickTree ft(n);
    for (int i = 0; i < n; ++i) {
        cout << ft.get(r[i] - 1) << " ";
        ft.put(p[i], 1);
    }
    cout << endl;
}
