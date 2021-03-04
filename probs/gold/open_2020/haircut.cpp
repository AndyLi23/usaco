#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update


using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 

#define FOR(i, n) for(long long (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(long long (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(long long (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

long long N, A[100000], k[100000];
unordered_map<long long, vector<long long> > m;

bool comp(long long a, long long b) {
    return A[a] < A[b];
}

int main() {
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;
    FOR(i, N) {
        cin >> A[i];

        m[A[i]].push_back(i);
    }

    Tree<long long> T;

    FOR2R(h, N, 0) {
        FOR(j, m[h].size()) {
            if(h < N-1) {
                k[h + 1] += T.order_of_key(m[h][j]);
            }

            //cout << k[m[h][j]] << endl;
        }

        FOR(j, m[h].size()) {
            T.insert(m[h][j]);
        }
    }

    FOR2(i, 1, N) {
        k[i] += k[i - 1];
    }

    FOR(i, N) {
        cout << k[i] << endl;
    }
}