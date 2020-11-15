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

int R, C, K;
int grid[100][100];
int dp[100][100];


int main() {
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
    //use cin >> and cout <<

    cin >> R >> C >> K; 

    FOR(i, R) {
        FOR(j, C) {
            cin >> grid[i][j];
        }
    }

    dp[0][0] = 1;

    FOR(i, R) {
        FOR(j, C) {
            FOR2(i1, i+1, R) {
                FOR2(j1, j+1, C) {
                    if(grid[i][j] != grid[i1][j1]) {
                        dp[i1][j1] += dp[i][j];
                        dp[i1][j1] %= 1000000007;
                    }
                }
            }
        }
    }

    cout << dp[R - 1][C - 1] << endl;
}