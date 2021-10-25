#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 2e5;

int L, N;
pair<int, int> a[100000];
int ans;

int main() {
    freopen("bobsled.in", "r", stdin);
    freopen("bobsled.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> L >> N;
    a[0] = {0, 1};
    FOR(i, N) {
        cin >> a[i+1].first >> a[i+1].second;
    }

    sort(a, a + N + 1);

    FOR(i, N) {
        a[i + 1].second = min(a[i + 1].second, a[i].second + a[i + 1].first - a[i].first);
    }

    FOR2R(i, N-1, 0) {
        a[i].second = min(a[i].second, a[i+1].second + a[i+1].first - a[i].first);
    }

    FOR(i, N) {
        ans = max(ans, max(a[i+1].second, a[i].second) + (a[i+1].first - a[i].first - abs(a[i+1].second - a[i].second)) / 2);

        // cout << ans << endl;
    }

    ans = max(ans, a[N].second + L - a[N].first);

    cout << ans << endl;
}