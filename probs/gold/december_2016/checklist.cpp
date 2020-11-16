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

int H, G, h[1001][2], g[1001][2], dp[1001][1001][2];

int main() {
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    //use cin >> and cout <<

    cin >> H >> G;
    FOR(i, H) {
        cin >> h[i][0] >> h[i][1];
    }
    FOR(i, G) {
        cin >> g[i][0] >> g[i][1];
    }
    FOR(i, H+1) {
        FOR(j, G+1) {
            dp[i][j][0] = 2000000000;
            dp[i][j][1] = 2000000000;
        }
    }

    dp[1][0][0] = 0;
    FOR2(i, 1, H+1) {
        FOR(j, G+1) {
            FOR(k, 2) {
                int x, y;
                if(k == 1) {
                    x = g[j - 1][0];
                    y = g[j - 1][1];
                } else {
                    x = h[i - 1][0];
                    y = h[i - 1][1];
                }

                if(i < H) {
                    dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + (x - h[i][0]) * (x - h[i][0]) + (y - h[i][1]) * (y - h[i][1]));
                }
                if(j < G) {
                    dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + (x - g[j][0]) * (x - g[j][0]) + (y - g[j][1]) * (y - g[j][1]));
                }
            }
        }
    }

    cout << dp[H][G][0] << endl;
}