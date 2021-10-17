#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 2e5;

int N, X, Y, ans, a, b, c, d;

struct Square {
    int start, end, top, bottom;
};

Square arr[MAXN];
pair<int, pair<int, int> > events[MAXN*2];
set<int> cur;

int main() {

    freopen("rplow2.in", "r", stdin);
    freopen("rplow2.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> X >> Y >> N;

    FOR(i, N) {
        cin >> a >> b >> c >> d;
        a--;
        d++;
        arr[i] = {a, c, b, d};
        events[2 * i] = {a, {1, i}};
        events[2 * i+1] = {c, {0, i}};
    }

    sort(events, events + 2 * N);

    int prevx = 0;

    FOR(i, 2*N) {
        vector<pair<int, pair<int, int> > > ev;
        int j = 0;
        for(int other : cur) {
            Square o = arr[other];
            ev.pb({o.top, {0, j}});
            ev.pb({o.bottom, {1, j}});
            j++;
        }

        if(ev.size() != 0) {
            sort(ev.begin(), ev.end());
            int prevy = ev[0].first;
            int len = 0;
            set<int> s;

            for(pair<int, pair<int, int> > p : ev) {
                if(s.size() != 0) {
                    len += p.first - prevy;
                }
                prevy = p.first;
                if(p.second.first == 0) {
                    s.insert(p.second.second);
                } else {
                    s.erase(s.find(p.second.second));
                }
            }

            ans += len * (events[i].first - prevx);
        }
        prevx = events[i].first;

        if(events[i].second.first == 1) {
            cur.insert(events[i].second.second);
        } else {
            cur.erase(cur.find(events[i].second.second));
        }
    }
    cout << ans << endl;
}