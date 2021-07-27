#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N, MOD;

//structures
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

//exp
long long exp(int base, int power){
   if(power == 0) return 1;
   if(power == 1) return (base + MOD) % MOD;
   long long ans = exp(base,power/2);
   ans = (ans * ans + MOD) % MOD;
   if(power%2 == 1) ans = (ans*base + MOD) % MOD;
   return (ans + MOD) % MOD;
}

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
    //------


    //initialize a struct
    Edge edge = Edge{5,3};
}