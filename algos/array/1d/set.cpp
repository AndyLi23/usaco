#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

//MULTISET: set with repeating elements
multiset<int> s;

//SET: only one element of each value
set<int> s1;

int main() {


    //add to set
    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(7);
    s.insert(2);
    s.insert(4);

    int i = 5;

    //find first element greater than or equal to i
    if(i <= *s.rbegin()) {
        auto it = s.lower_bound(i);
        cout << *it << endl;
    }
    //find first element less than i
    if(i > *s.begin()) {
        auto it1 = prev(s.lower_bound(i));
        cout << *it1 << endl;
    }

    //erase first/last element
    s.erase(s.begin());
    s.erase(prev(s.end()));
}