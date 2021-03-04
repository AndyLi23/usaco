#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N, A[100000], l[100000], r[100000], ans;

int main() {
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    Tree<int> T;

    FOR(i, N) {
        cin >> A[i];
        l[i] = i - T.order_of_key(A[i]);
        T.insert(A[i]);
    }

    Tree<int> T1;

    FOR2R(i, N-1, 0) {
        r[i] = N - 1 - i - T1.order_of_key(A[i]);
        T1.insert(A[i]);
    }

    FOR(i, N) {
        if(l[i] < r[i]) {
            if(l[i] * 2 < r[i]) {
                ans++;
            }
        } else {
            if(l[i] > 2*r[i]) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}