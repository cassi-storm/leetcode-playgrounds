#include <bits/stdc++.h>
using namespace std;


class Puzzle {
private:
    int n, h;
    vector<int> a, sol;
    set<long long> states;
    vector<pair<int, int>> shifts = {
		{-1, 0}, {1, 0}, {0, -1}, {0, 1}
	};
    int distance(vector<int> &a) {
        int sum_ = 0;
        for (int i = 0; i < n; ++i) {
            if (!a[i]) continue;
            sum_ += manhattan(i, a[i] - 1);
        }
        return sum_;
    }
    int manhattan(int p, int x) {
        return abs(p / h - x / h) + abs(p % h - x % h);
    }
    bool isSolvable() {
        int count = 0, pos = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                a[i] && a[j] && a[i] > a[j] && ++count;
            }
            if (!a[i]) pos = i / h;
        }
        if (h % 2 == 1) {
            return !(count % 2);
        } 
        return (count % 2 + (h - pos) % 2 == 1);
    }
    void visitState(vector<int> &a) {
        long long state = 0;
        for (auto i : a) {
            state = 2 * state + i;
        }
        states.insert(state);
    }
	void unVisitState(vector<int> &a) {
        long long state = 0;
        for (auto i : a) {
            state = 2 * state + i;
        }
        states.erase(states.find(state));
    }
    bool isStateVisited(vector<int> &a) {
        long long state = 0;
        for (auto i : a) {
            state = 2 * state + i;
        }
        return states.find(state) != states.end();
    }
    bool solve(int cr, int depth) {
        if (!distance(a)) { 
            printPuzzle();
            cout << endl;
			cout << "Depth : " << depth << endl;
            return true;
        } 
        if (isStateVisited(a)) {
            return false;
        }
        int shf = 0, x = cr / h, y = cr % h;
        vector<pair<int, int>> st;
        visitState(a);
        for (auto i : shifts) {
            shf = h * (x + i.first) + (y + i.second);
            a[cr] = a[shf]; 
            a[shf] = 0;
            if (!(x + i.first == -1 || x + i.first == h 
                  || y + i.second == -1 || y + i.second == h)) {
                st.push_back({distance(a), 10 * i.first + i.second});
            }
            a[shf] = a[cr]; 
            a[cr] = 0;
        }
        sort(st.begin(), st.end());
        int r, c;
        for (auto i : st) {
            r = x + i.second / 10;
            c = y + i.second % 10;
            shf = h * r + c;
            a[cr] = a[shf]; 
            a[shf] = 0;
            sol.push_back(i.second);
            if (solve(shf, depth + 1)) {
                a[shf] = a[cr]; 
                a[cr] = 0;
                // printPuzzle();
                // cout << endl;
                return true;
            }
            a[shf] = a[cr]; 
            a[cr] = 0;
            sol.pop_back();
        }
		unVisitState(a);
        return false;
    }
public:
    Puzzle(int h) {
        this->h = h;
        n = h * h;
        a = vector<int> (n);
    }
    Puzzle(int h, vector<int> &v) {
        this->h = h;
        n = h * h;
        a = vector<int> (n);
        for (int i = 0; i < n; ++i) {
            a[i] = v[i];
        }
    }
    bool solvePuzzle() {
        if (!isSolvable()) {
            cout << "not Solvable" << endl;
            return false;
        }
        int p = -1;
        for (int i = 0; i < n; ++i) {
            if (!a[i]) {
                p = i;
                break;
            }
        }
        cout << "\nSolution : \n";
        bool result = solve(p, 0);
        return result;
    }
    void printPuzzle() {
        for (int i = 0; i < n; ++i) {
            if (i && i % h == 0) cout << endl;
            cout << a[i] << " ";
        }
        cout << endl;
    }
    int size() {
        return h;
    }
};



int main() {
    int n;
    cin >> n;
    vector<int> a(n * n);
    for (auto &i : a) {
        cin >> i;
    }
    Puzzle p(n, a);
    p.solvePuzzle();
    return 0;
}



/**
solvable:
4
13 2 10 3
1 12 8 4
5 0 9 6
15 14 11 7

3
1 8 2
0 4 3
7 6 5

4
6 13 7 10
8 9 11 0
15 2 12 5
14 3 1 4

4
9 14 4 3
7 6 5 8 
1 10 11 12 
13 2 15 0

unsolvable:
4
3 9 1 15
14 11 4 6 
13 0 10 12
2 7 8 5
*/
