#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 2e5;

int N, A[100000];
ll cnt, start, ans;


ll squaresum(ll v) {
    return v * (v + 1) * (2 * v + 1) / 6;
}

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N;

    FOR(i, N) {
        cin >> A[i];
        cnt = max(0ll, cnt + A[i] - 1);
    }

    FOR(i, N) {
        if(cnt == 0) {
            start = (i) % N;
            break;
        }
        cnt = max(0ll, cnt + A[i] - 1);
    }

    cout << start << endl;

    FOR(i, N) {
        int cur = (start + i) % N;
        ans += squaresum((ll)A[cur] + (ll)cnt - 1ll) - squaresum((ll)cnt - 1ll);
        cnt = max(0ll, cnt + A[cur] - 1);
    }

    cout << ans << endl;
}