#include <bits/stdc++.h>
using namespace std;

struct node {
    bool end;
    node *child[26];
    node() {
        end = false;
        for (int i = 0; i < 26; ++i) {
            child[i] = NULL;
        }
    }
};

class Trie {
private:
    node* root;
    void printAll(node *root_, string &s) {
        if (!root_) return;
        if (root_->end) {
            cout << s << endl;
        }
        for (int i = 0; i < 26; ++i) {
            s.push_back(i + 97);
            printAll(root_->child[i], s);
            s.pop_back();
        }
    }
public:
    Trie() {
        root = new node();
    }
    void insert(string s) {
        node *node_ = root;
        int lt = s.size();
        for (int i = 0; i < lt; ++i) {
            if (!node_->child[s[i] - 97]) {
                node_->child[s[i] - 97] = new node();
            }
            node_ = node_->child[s[i] - 97];
        } 
        node_->end = true;
    }
    int find(string s) {
        node *node_ = root;
        int lt = s.size();
        for (int i = 0; i < lt; ++i) {
            if (!node_->child[s[i] - 97]) {
                return false;
            }
            node_ = node_->child[s[i] - 97];
        }
        return node_->end;
    }
    void printAllStrings() {
        string s = "";
        printAll(root, s);
    }
};


int main() {
    Trie trie;
    trie.insert("aerospace");
    trie.insert("hello");
    trie.insert("hell");
    trie.insert("apple");
    trie.insert("aeroplane");
    trie.insert("aero");
    trie.printAllStrings();
    return 0;
}
