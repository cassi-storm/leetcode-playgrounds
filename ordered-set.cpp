#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define endl "\n"
#define at find_by_order
#define index order_of_key
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/** Bugged intersection */
typedef tree<
    pair<int, int>, 
    null_type, 
    less_equal<pair<int, int>>,
    rb_tree_tag, 
    tree_order_statistics_node_update
> ordered_map;

class MyCalendarThree {
private:
    ordered_map map_1, map_2; 
public:
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        int c1 = map_1.index({end, end}) - map_1.index({start, INT_MIN});
        int c2 = map_2.index({end, INT_MIN}) - map_2.index({start, start});
        int c3 = map_1.index({end, end}) - map_2.index({start, start});
        map_1.insert({end, start});
        map_2.insert({start, end});
        int result = c1 + c2 - c3 + 1;
        return result;
    }
};
/** end */

int32_t main() {
    ordered_set set_;
    set_.insert(1);    
    set_.insert(10);
    set_.insert(2);
    set_.insert(7);
    set_.insert(2);
    set_.insert(17);
    for (auto i : set_) {
        cout << i << " ";
    }
    cout << endl;
    cout << "1-index : " << *set_.at(1) << endl;
    cout << "get-index : " << set_.index(17) << endl;
    cout << "get-index : " << set_.index(10) << endl;
    cout << "get-index : " << set_.index(2) << endl;
    set_.erase(2);
    for (auto i : set_) {
        cout << i << " ";
    }
    return 0;
}
