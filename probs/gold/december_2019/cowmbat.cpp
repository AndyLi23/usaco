#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 1e5+5;

int N, M, K, a[26][26], cost[MAXN][26], psum[MAXN][26];
int dp[MAXN][26], dpmin[MAXN];
string s;

int main() {
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> M >> K;
    cin >> s;

    FOR(i, M) FOR(j, M) cin >> a[i][j];
    FOR(k, M) FOR(i, M) FOR(j, M) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);

    FOR(i, N) {
        FOR(j, M) {
            cost[i][j] = a[s[i] - 'a'][j];
            psum[i][j] = cost[i][j];
        }
    }

    FOR2(i, 1, N) {
        FOR(j, M) {
            psum[i][j] += psum[i - 1][j];
        }
    }

    FOR(i, N+1) {
        FOR(j, M) {
            dp[i][j] = INT_MAX;
        }
    }

    fill(dpmin + 1, dpmin + N + 1, INT_MAX);

    FOR2(i, 1, N+1) {
        FOR(j, M) {
            if(dp[i-1][j] != INT_MAX) { //INT_MAX means not possible: (if i < K)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost[i - 1][j]);
            }
            if(i >= K && dpmin[i-K] != INT_MAX) { //only possible to replace last K if length i-K is possible or i == K (dpmin[0] = 0): cannot have AABBB for K=3, 
                                                  //for example, since dpmin[5-3=2] would be impossible
                dp[i][j] = min(dp[i][j], dpmin[i-K] + psum[i-1][j] - psum[i - K - 1][j]);
            }

            dpmin[i] = min(dpmin[i], dp[i][j]);
        }
    }

    cout << dpmin[N] << "\n";
}