#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 2e5;

int N, K, ans, a, b;

struct Square {
    int start, end, top, bottom;
};

Square arr[50000];
pair<int, pair<int, int> > events[100000];
set<int> cur;

int main() {
    freopen("squares.in", "r", stdin);
    freopen("squares.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> K;
    K /= 2;

    FOR(i, N) {
        cin >> a >> b;
        arr[i] = {a - K, a + K, b + K, b - K};
        events[2 * i] = {a - K, {1, i}};
        events[2 * i+1] = {a + K, {0, i}};
    }

    sort(events, events + 2 * N);

    FOR(i, 2*N) {
        if(events[i].second.first == 1) {
            Square s = arr[events[i].second.second];
            for(int other : cur) {
                Square o = arr[other];
                if(!(o.top < s.bottom || o.bottom > s.top)) {
                    if((min(o.top, s.top) - max(o.bottom, s.bottom)) * (min(o.end, s.end) - max(o.start, s.start)) > 0) {
                        if(ans == 0) {
                            ans = (min(o.top, s.top) - max(o.bottom, s.bottom)) * (min(o.end, s.end) - max(o.start, s.start));
                        } else {
                            ans = -1;
                            break;
                        }
                    }
                }
            }
            cur.insert(events[i].second.second);
        } else {
            cur.erase(cur.find(events[i].second.second));
        }
    }
    cout << ans << endl;
}