#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N, MOD;

//structures-----
struct Point {
    int x,y;
    bool operator<(const Point &p) {
        if(x==p.x) return y<p.y;
        else return x<p.x;
    }
};

struct Edge {
    int weight, dest;
    bool operator<(const Edge &e) {
        if(dest==e.dest) return weight<e.weight;
        else return dest<e.dest;
    }
};

//exp------
long long exp(int base, int power){
   if(power == 0) return 1;
   if(power == 1) return (base + MOD) % MOD;
   long long ans = exp(base,power/2);
   ans = (ans * ans + MOD) % MOD;
   if(power%2 == 1) ans = (ans*base + MOD) % MOD;
   return (ans + MOD) % MOD;
}


//tree------
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 

//rope (log n deletion and indexing)
#include <ext/rope>
using namespace __gnu_cxx;
rope<int> r;


bool check(int i) {return true;}

int main() {
    //binary search
    int i = 0, j = N, m, ans;
    //find minimum value that works (to find maximum, reverse j= and i=)
    while (i <= j) {
        m = (i+j)/2;
        if(check(m)) {
            ans = m;
            j = m - 1;
        } else {
            i = m + 1;
        }
    }


    //set----

    set<int> s;

    //find first element greater than or equal to i
    if(i <= *s.rbegin()) {
        auto it = s.lower_bound(i);
    }
    //find first element less than i
    if(i > *s.begin()) {
        auto it1 = prev(s.lower_bound(i));
    }

    //erase first/last element
    s.erase(s.begin());
    s.erase(prev(s.end()));
    //------

    /*tree------
    Tree<int> T;
    T.insert(0);
    T.insert(3);
    T.insert(5);

    //get iterator of element at index 2 -> 5
    cout << *T.find_by_order(2) << endl;
    //get number of elements less than 4 -> 2
    cout << T.order_of_key(4) << endl;*/


    //rope-------
    r.push_back(1);
    r.push_back(2);
    r.pop_back();
    int temp = r[0];
    //erase 1 element starting from index 0
    r.erase(0, 1);

    //initialize a struct
    Edge edge = Edge{5,3};
}