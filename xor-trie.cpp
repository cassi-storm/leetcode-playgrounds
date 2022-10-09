#include <bits/stdc++.h>
using namespace std;

struct node {
    bool end;
    node *child[2];
    node() {
        child[0] = child[1] = NULL;
    }
};

class XORTrie {
private:
    int height = 30;
    node* root;
public:
    XORTrie() {
        root = new node();
    }
    void insert(int x) {
        node *node_ = root;
        int bit = 1 << height;
        while (bit) {
            if (!node_->child[(bit & x) != 0]) {
                node_->child[(bit & x) != 0] = new node();
            }
            node_ = node_->child[(bit & x) != 0];
            bit >>= 1;
        } 
    }
    int get(int x) {
        node *node_ = root;
        int z = 0, bit = 1 << height;
        while (bit) {
            if (node_->child[1 - ((bit & x) != 0)]) {
                z = 2 * z + (1 - ((bit & x) != 0));
                node_ = node_->child[1 - ((bit & x) != 0)];
            } else {
                z = 2 * z + ((bit & x) != 0);
                node_ = node_->child[(bit & x) != 0];
            }
            bit >>= 1;
        }
        return z;
    }
};

int main() {
    XORTrie trie;
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    trie.insert(a[0]);
    for (auto i : a) {
        int x = trie.get(i);
        cout << i << " " << x << " "<< (i ^ x) << endl;
        trie.insert(i);
    }
}
