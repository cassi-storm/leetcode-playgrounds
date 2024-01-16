#include <bits/stdc++.h>
using namespace std;

vector<int> get_all_occurrences(string text, string pattern) {
    string s = pattern + "#" + text;
    int n = s.size();
    vector<int> v(s.size(), 0);
    int ln = 0;
    for (int i = 1; i < n; ++i) {
        while (ln && s[i] != s[ln]) {
            ln = v[ln - 1];
        }
        if (s[i] == s[ln]) {
            ++ln;
		}
        v[i] = ln;
    }
    int m = pattern.size();
    vector<int> occurs;
    for (int i = 0; i < n; ++i) {
        if (v[i] == m) {
            occurs.push_back(i - 2 * m);
        }
    }
    return occurs;
}

int main() {
    auto x = get_all_occurrences("sandyblazekksjdklasandykasjdlasandysandylklajssandy", "sandy");
    for (auto i : x) {
        cout << i << " ";
    }
    cout << "\nHello, World!\n";
}
