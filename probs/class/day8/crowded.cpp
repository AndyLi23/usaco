#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 2e5;

int N, D, ans;
pair<int, int> a[100000];
multiset<int> t;
bool leftc[100000], rightc[100000];

int main() {
    freopen("crowded.in", "r", stdin);
    freopen("crowded.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> D;

    FOR(i, N) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + N);

    int prev_ = 0;

    FOR(i, N) {
        while(a[i].first - a[prev_].first > D) {
            t.erase(t.find(a[prev_].second));
            prev_++;
        }

        if(t.size() > 0 && (*t.rbegin() >= 2*a[i].second)) {
            leftc[i] = 1;
        }

        t.insert(a[i].second);
    }

    t.clear();

    prev_ = N - 1;
    FOR2R(i, N-1, 0) {
        while(a[prev_].first - a[i].first > D) {
            t.erase(t.find(a[prev_].second));
            prev_--;
        }

        if(t.size() > 0 && (*t.rbegin() >= 2*a[i].second)) {
            rightc[i] = 1;
        }

        t.insert(a[i].second);
    }

    FOR(i, N) {
        // cout << leftc[i] << endl;
        if(leftc[i] && rightc[i]) ans++;
    }

    cout << ans << endl;
}