int pal_substr(string& s) {
    int n = 3 + 2 * s.size();
    vector<char> v(n, '#');
    v[0] = '^', v[n - 1] = '$';
    for (int i = 0; i < s.size(); ++i) {
        v[2 * i + 2] = s[i];
    }
    
    int C = 0, R = 0;
    vector<int> P(n, 0);
    for (int i = 1; i < n - 1; ++i) {
        int M = 2 * C - i;
        if (i < R) {
            P[i] = min(R - i, P[M]);
        }
        while (v[i + P[i] + 1] == v[i - P[i] - 1]) {
            ++P[i];
        }
        if (R < i + P[i]) {
            C = i, R = i + P[i];
        }
    }
    
    int max_ = 0;
    for (int i = 2; i < n - 2; ++i) {
        int idx = (i - 1 - P[i]) / 2;
        if (!idx) {
            max_ = max(max_, P[i]);
        }
    }
    
    return s.size() - max_;
}
