#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N, M, C, c[1000], a, b, dp[1000][1000], ans, cur, v[1000][1000];
unordered_map<int, vector<int> > m;

int main() {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M >> C;

    FOR(i, N) {
        cin >> c[i];
    }

    FOR(i, M) {
        cin >> a >> b; a--; b--;
        m[a].push_back(b);
    }

    v[0][0] = 1;

    FOR2(i, 1, 1000) {

        FOR(l, N) {
            if(v[i-1][l]) {
                cur = l;

                FOR(j, m[cur].size()) {
                    dp[i][m[cur][j]] = max(dp[i][m[cur][j]], dp[i - 1][cur] + c[m[cur][j]]);

                    v[i][m[cur][j]] = 1;

                    if(m[cur][j] == 0) {
                        ans = max(ans, dp[i][m[cur][j]] - C * i * i);
                    }
                
                }
            }
        }

    }

    cout << ans << endl;
}