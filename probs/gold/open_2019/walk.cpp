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

int N, K, visited[10000];

long long D[10000];

void prims(int source) {
    FOR2(i, 1, N+1) {
        D[i] = 100000000000;
    }    
    FOR(iter, N) {
        //find closest unexplored node
        int min_i = 0;
        FOR2(i, 1, N+1) {
            if (!visited[i] && (min_i==0 || D[i] < D[min_i])) {
                min_i = i;
            }
        }
        //mark as explored
        visited[min_i] = 1;

        //update all unvisited nodes - if they have minimum distance to the current mode
        FOR2(j, 1, N+1) {
            if (!visited[j]) {
                D[j] = min(D[j], (2019201913LL*min(min_i,j)+2019201949LL*max(min_i,j)) % 2019201997LL);
            }
        }
    }
}

int main() {
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> K;

    prims(1);

    sort(D + 1, D + N + 1);
    cout << D[N - K + 1];
}