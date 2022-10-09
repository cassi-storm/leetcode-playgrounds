#include <bits/stdc++.h>
#include <stdlib.h>
#define int long long
using namespace std;

void rsort(vector<int> &a) {
    int n = a.size();
    const int base = 256;
    vector<int> op(n);
    for (int i = 0, exp_ = 1; i < 4; ++i, exp_ *= base) {
        vector<int> count(base, 0);
        for (auto i : a) 
            ++count[(i / exp_) % base];
        for (int i = 1; i < base; ++i) 
            count[i] += count[i - 1];
        for (int i = n - 1; i > -1; --i) 
            op[--count[(a[i] / exp_) % base]] = a[i];
        for (int i = 0; i < n; ++i) 
            a[i] = op[i];
    }
}

int32_t main() {
    int n = 1000000;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = rand();
    }
    rsort(a);
    int flag = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] > a[i]) {
            flag = 0;
            break;
        }
    }
    cout << n << " " << flag << endl;
}
