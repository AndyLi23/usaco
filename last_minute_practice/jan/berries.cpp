#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N, K, b[1000], m, ans;

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> K;

    FOR(i, N) {
        cin >> b[i];
        m = max(m, b[i]);
    }

    FOR2(i, 1, m+1) {
        int full = 0;
    }
}