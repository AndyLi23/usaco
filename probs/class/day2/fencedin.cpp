#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
const int MOD = 1000000007;
const int MAXN = 2010;



int A, B, n, m, VA[MAXN], HA[MAXN], Va[MAXN], Ha[MAXN];
ll ans = 0;

int seen[MAXN * MAXN];
int seen_num = 0;

class comp { public: bool operator() (pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) { return a > b; } };

priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, comp> pq;

ll prims() {
    pq.push({0, {0, 0}});

    int cost;
    pair<int, pair<int, int> > temp;
    pair<int, int> cur;

    while (seen_num < n*m) {
        temp = pq.top();
        pq.pop();

        cost = temp.first;
        cur = temp.second;

        if(!seen[cur.first*MAXN + cur.second]) {

            //cout << cost << " " << cur.first << " " << cur.second << endl;

            seen[cur.first*MAXN + cur.second] = 1;
            ans += cost;
            seen_num++;

            if(cur.first < m-1) {
                pq.push({VA[cur.second], {cur.first + 1, cur.second}});
            }
            if(cur.first > 0) {
                pq.push({VA[cur.second], {cur.first - 1, cur.second}});
            }
            if(cur.second < n-1) {
                pq.push({HA[cur.first], {cur.first, cur.second + 1}});
            }
            if(cur.second > 0) {
                pq.push({HA[cur.first], {cur.first, cur.second - 1}});
            }
        }
    }
    //cout << seen_num << endl;
    return ans;
}


int main() {
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> A >> B >> n >> m;

    FOR(i, n) cin >> Va[i];
    FOR(i, m) cin >> Ha[i];

    sort(Va, Va+n);
    for (int i = 1; i < n; i++) {
        VA[i] = Va[i] - Va[i-1];
    }
    VA[0] = Va[0];
    VA[n] = B - Va[n-1];

    sort(Ha, Ha + m);
    for (int i = 1; i < m; i++) {
        HA[i] = Ha[i] - Ha[i-1];
    }
    HA[0] = Ha[0];
    HA[m] = A - Ha[m-1];
    n++;
    m++;

    prims();

    cout << ans << endl;
}