#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 2e5;

int N, C, ans;
pair<int, int> cows[1000];

struct line {
    int x0, y0, x1, y1;
};

line lines[1000];
int polygon[1000];
bool seen[1000];

vector<int> polygons[1000];

void dfs(int i, int p) {
    polygon[i] = p;
    polygons[p].pb(i);
    seen[i] = true;

    FOR(j, N) {
        if(!seen[j] && ((lines[i].x0 == lines[j].x0 && lines[i].y0 == lines[j].y0) ||
        (lines[i].x1 == lines[j].x0 && lines[i].y1 == lines[j].y0) ||
        (lines[i].x1 == lines[j].x1 && lines[i].y1 == lines[j].y1) ||
        (lines[i].x0 == lines[j].x1 && lines[i].y0 == lines[j].y1))) {
            dfs(j, p);
        }
    }
}

bool ccw(long long x0, long long y0, long long x1, long long y1, long long x2, long long y2) {
    return (y2 - y0) * (x1 - x0) > (y1 - y0) * (x2 - x0);
}

bool intersect(int x, int y, int i) {
    return ccw(x, y, lines[i].x0, lines[i].y0, lines[i].x1, lines[i].y1) != ccw(-1, y, lines[i].x0, lines[i].y0, lines[i].x1, lines[i].y1) &&
           ccw(x, y, -1, y, lines[i].x0, lines[i].y0) != ccw(x, y, -1, y, lines[i].x1, lines[i].y1);
}

int main() {
    freopen("crazy.in", "r", stdin);
    freopen("crazy.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> C;

    FOR(i, N) {
        cin >> lines[i].x0 >> lines[i].y0 >> lines[i].x1 >> lines[i].y1;
    }

    FOR(i, C) {
        cin >> cows[i].first >> cows[i].second;
    }

    int p = 1;

    FOR(i, N) {
        if(!seen[i]) {
            dfs(i, p);
            p++;
        }
    }

    map<vector<int>, int> m;

    FOR(i, C) {
        vector<int> temp;
        temp.pb(1);
        FOR2(j, 1, p) {
            int it = 0;

            for(auto k : polygons[j]) {
                if(!(lines[k].y0 == lines[k].y1 && lines[k].y0 == cows[i].second)) {
                    if(intersect(cows[i].first, cows[i].second, k)) {
                        it++;
                    }
                }
            }

            temp.pb(it % 2 != 0);
        }

        /*for(auto k : temp) {
            cout << k << " ";
        }
        cout << endl;*/

        m[temp]++;
        ans = max(ans, m[temp]);
    }

    cout << ans << endl;
}