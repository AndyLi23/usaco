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

int N, A, B, na, nb, ans;
bool dp[2][5000005];

int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> A >> B;

    dp[0][A] = true;
    dp[0][B] = true;

    FOR(i, 2) {
        FOR(j, N+1) {
            if(dp[i][j]) {
                if(i == 0) {
                    dp[1][j / 2] = true;
                }
                if(j+A <= N) {
                    dp[i][j + A] = true;
                }
                if(j+B <= N) {
                    dp[i][j + B] = true;
                }
                ans = max(ans, j);
            }
        }
    }

    cout << ans << endl;
}