#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
#define MAXN = 2e5;


//RUNNING:
//g++ -O task.cpp

int N;
int teams[2000], dist[2000];
bool seen[2000];

int main() {
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;
    FOR(i, N) cin >> teams[i];

    ll ans = 0;

    FOR(i, N) {
        int j = -1;
        FOR(k, N) {
            if(!seen[k] && (j == -1 || dist[k] > dist[j])) {
                j = k;
            }
        }

        ans += dist[j];
        seen[j] = true;
        FOR(k, N) {
            dist[k] = max(dist[k], teams[j] ^ teams[k]);
        }
    }

    cout << ans << endl;
}