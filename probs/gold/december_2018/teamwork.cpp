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

int N, K, A[10000], dp[10000], mx;

int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> K;

    FOR(i, N) {
        cin >> A[i];
    }

    FOR(i, N) {
        mx = A[i];
        for(int j=i;j>=0 && i+1-j <= K; j--) {
            mx = max(A[j], mx);
            if(j == 0) {
                dp[i] = max(dp[i], mx * (i + 1 - j));
            } else {
                dp[i] = max(dp[i], dp[j - 1] + mx * (i + 1 - j));
            }
        }
    }

    cout << dp[N - 1] << endl;
}