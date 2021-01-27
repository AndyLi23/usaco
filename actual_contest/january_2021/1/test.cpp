#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N, K, a[200000], b[200000], temp, arr[100000], p;
unordered_map<int, set<int> > m;


int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout); 
    //use cin >> and cout <<

    cin >> N >> K;

    FOR(i, N) {
        arr[i] = i;
        m[i].insert(i);
    }

    FOR(i, K) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    FOR(j, 20) {
        FOR(i, K) {
            temp = arr[a[i]];
            arr[a[i]] = arr[b[i]];
            arr[b[i]] = temp;

            m[arr[b[i]]].insert(b[i]);
            m[arr[a[i]]].insert(a[i]);
        }
    }

    FOR(i, N) {
        cout << m[i].size() << endl;
    }
}