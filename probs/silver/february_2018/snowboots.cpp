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

int N, B, curTile, cur;
int best = 999;
int tiles[255], seen[255][255], S[255], D[255];

bool get(int i, int s) {
    return i < N && tiles[i] <= s;
}

void DFS(int i, int b) {

    if(seen[i][b] != 0) {
        return;
    }

    seen[i][b] = 1;

    if(i == N-1) {
        best = min(best, b);
        return;
    }

    FOR2(j, 1, D[b]+1) {
        if(i+j < N && tiles[i+j] <= S[b]) {
            DFS(i + j, b);
        }
    }

    FOR2(b2, b+1, B) {
        if(tiles[i] <= S[b2]) {
            DFS(i, b2);
        }
    }
}

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> B;

    FOR(i, N) {
        cin >> tiles[i];
    }

    FOR(i, B) {
        cin >> S[i] >> D[i];
    }

    DFS(0 ,0);

    cout << best << endl;
}