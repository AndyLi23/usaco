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

int N, K, A[401], dp[401][401];

int main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> K;


    int curmax = 0;
    int total = 0;

    FOR2(i, 1, N+1) {
        cin >> A[i];

        curmax = max(curmax, A[i]);
        total += A[i];

        dp[i][0] = (i) * curmax;

        FOR2(k, 1, K+1) {
            dp[i][k] = 1000000000;
            int tempmax = A[i];

            FOR2R(j, i-1, 0) {
                dp[i][k] = min(dp[i][k], dp[j][k - 1] + tempmax * (i - j));
                tempmax = max(tempmax, A[j]);
            }
        }
    }

    /*FOR(i, N+1) {
        FOR(j, K+1) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << dp[N][K] - total << endl;
}