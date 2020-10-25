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


    FOR(i, 10) {
        //find first element greater than i
        multiset<int>::iterator it = s.lower_bound(i);

        //find first element less than i
        multiset<int>::iterator it1 = s.upper_bound(i);

        if(it != s.end()) {
            cout << *it << endl;

            //remove from set
            s.erase(it);
        }
    }
}