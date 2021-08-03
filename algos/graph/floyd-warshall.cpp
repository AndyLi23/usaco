#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N, dist[100000][100000];

void fw() {
    FOR(i, N) {
        FOR(j, N) {
            if (i==j) dist[i][j]=0;
            else if (!dist[i][j]) dist[i][j] = INT_MAX;
        }
    }
    FOR(k, N) {
        FOR(i, N) {
            FOR(j, N) {
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

}

int main() {
    N = 5;





    //testing--
    dist[0][1] = 5;
    dist[1][0] = 5;
    dist[2][1] = 2;
    dist[1][2] = 2;
    dist[0][3] = 9;
    dist[3][0] = 9;
    dist[0][4] = 1;
    dist[4][0] = 1;
    dist[3][4] = 2;
    dist[4][3] = 2;
    dist[3][2] = 7;
    dist[2][3] = 7;

    FOR(i, N) {
        FOR(j, N) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    fw();

    FOR(i, N) {
        FOR(j, N) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}