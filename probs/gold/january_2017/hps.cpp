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

int N, K, o1, o2, ans, a[100000], dp[100001][21][3];;
char temp;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> K;

    FOR(i, N) {
        cin >> temp;
        if(temp == 'H') {
            a[i] = 0;
        } else if (temp == 'P') {
            a[i] = 1;
        } else {
            a[i] = 2;
        }
    }

    FOR(i, N+1) {
        FOR(j, K+1) {
            FOR(k, 3) {
                if(i == 0) {
                    dp[i][j][k] = 0;
                } else {
                    if(j == 0) {
                        dp[i][j][k] = dp[i - 1][j][k] + (a[i - 1] == k);
                    } else {
                        o1 = (k + 1) % 3;
                        o2 = (k + 2) % 3;
                        dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i - 1][j - 1][o1]), dp[i - 1][j - 1][o2]) + (a[i - 1] == k);
                    }
                }
            }
        }
    }

    FOR(j, K+1) {
        ans = max(ans, max(dp[N][j][0], max(dp[N][j][1], dp[N][j][2])));
    }

    cout << ans << endl;
}