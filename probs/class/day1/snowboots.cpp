#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
const int MOD = 1000000007;
const int MAXN = 2e5;

int N, B, ans[100000], pre[100000], aft[100000];
pair<int, int> t[100000];
pair<int, pair<int, int> > p[100000];

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> B;

    FOR(i, N) {
        cin >> t[i].first;
        t[i].second = i;
        pre[i] = i - 1;
        aft[i] = i + 1;
    }

    FOR(i, B) {
        cin >> p[i].first >> p[i].second.first;
        p[i].second.second = i;
    }

    sort(p, p + B);
    sort(t, t + N);

    int cur_tile = N - 1;
    int cur_max_dist = 1;

    FOR2R(i, B-1, 0) {
        int md = p[i].first;
        int dist = p[i].second.first;
        while(cur_tile >= 0 && t[cur_tile].first > md) {
            int cur = t[cur_tile].second;
            aft[pre[cur]] = aft[cur];
            pre[aft[cur]] = pre[cur];
            cur_max_dist = max(cur_max_dist, aft[cur] - pre[cur]);
            cur_tile--;
        }

        ans[p[i].second.second] = (cur_max_dist <= dist);
    }

    FOR(i, B) {
        cout << ans[i] << endl;
    }
}