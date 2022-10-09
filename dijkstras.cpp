#include <bits/stdc++.h>
using namespace std;

class DijkstrasMinHeap {
private:
    int n, size;
    vector<int> a;
    vector<pair<int, int>> heap;
    void update(int x, int v) {
        if (heap[a[x]].first <= v) 
            return;
        int i = a[x];
        heap[i].first = v;
        pair<int, int> temp;
        while (i != 0 && heap[(i - 1) / 2].first > heap[i].first) {
            temp = heap[(i - 1) / 2];
            heap[(i - 1) / 2] = heap[i];
            heap[i] = temp;
            a[heap[i].second] = i;
            i = (i - 1) / 2;
            a[heap[i].second] = i;
        }
    }
    void pop_item() {
        a[heap[0].second] = -1;
        --size;
        heap[0] = heap[size];
        int i = 0, max_ = 0;
        pair<int, int> temp;
        while (true) {
            if (2 * i + 1 < size && heap[max_].first > heap[2 * i + 1].first) 
                max_ = 2 * i + 1;
            if (2 * i + 2 < size && heap[max_].first > heap[2 * i + 2].first)
                max_ = 2 * i + 2;
            if (max_ == i) break;
            temp = heap[max_];
            heap[max_] = heap[i];
            heap[i] = temp;
            a[heap[i].second] = i;
            i = max_;
            a[heap[i].second] = i;
        }
    }
public:
    DijkstrasMinHeap(int x) {
        n = x, size = 0;
        a = vector<int> (x, -1);
        heap = vector<pair<int, int>> (x);
    }
    void push(pair<int, int> x) {
        if (a[x.second] == -1) {
            heap[size] = x;
            ++heap[size].first;
            a[x.second] = size;
            ++size;
        }
        update(x.second, x.first);
    }
    void pop() {
        pop_item();
    }
    pair<int, int> top() {
        return heap[0];
    }
    int heapsize() {
        return this->size;
    }
    // not used methods
    void printHeap() {
        for (int i = 0; i < size; ++i) {
            cout << "(" << heap[i].first << ", " << heap[i].second << ") ";
        }
        cout << endl;
    }
    void printA() {
        for (auto i : a) {
            cout << i << " ";
        }
        cout << endl;
    }
};

vector<int> dijkstras(vector<vector<int>> &graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX / 2), vi(n, 0);
    dist[start] = 0;
    DijkstrasMinHeap heap(n);
    heap.push({0, start});
    int d, node;
    while (heap.heapsize()) {
        d = heap.top().first, node = heap.top().second;
        vi[node] = 1;
        heap.pop();
        for (auto i : graph[node]) {
            if (dist[node] + 1 < dist[i] && !vi[i]) {
                dist[i] = dist[node] + 1;
                heap.push({dist[i], i});
            }
        }
    }
    return dist;
}


void test_heap() {
    int n = 10;
    DijkstrasMinHeap heap(n);
    heap.push({5, 1});
    heap.push({0, 0});
    heap.push({2, 2});
    heap.printHeap();
    heap.printA();
    heap.push({3, 9});
    heap.push({7, 8});
    heap.push({1, 5});
    heap.printHeap();
    heap.printA();
    heap.pop();
    heap.printHeap();
    heap.printA();
    heap.push({0, 8});
    heap.printHeap();
    heap.printA();
    heap.push({1, 8});
    heap.printHeap();
    heap.printA();
}

int main() {
    test_heap();
    return 0;
}
