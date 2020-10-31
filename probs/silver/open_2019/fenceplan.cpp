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

int N, M, ans, t1, t2;

int x[100005];
int y[100005];
bool seen[100005];

int minx, maxx, miny, maxy;

unordered_map<int, vector<int> > graph;

void DFS(int cur) {
    if(!seen[cur]) {
        seen[cur] = true;
        minx = min(minx, x[cur]);
        maxx = max(maxx, x[cur]);
        miny = min(miny, y[cur]);
        maxy = max(maxy, y[cur]);

        FOR(i, graph[cur].size()) {
            DFS(graph[cur][i]);
        }
    }
}

int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M;

    FOR2(i, 1, N+1) {
        cin >> x[i] >> y[i];
    }

    FOR(i, M) {
        cin >> t1 >> t2;
        graph[t1].push_back(t2);
        graph[t2].push_back(t1);
    }

    ans = 999999999;

    FOR2(i, 1, N+1) {
        if (!seen[i]) {
            maxx = 0;
            maxy = 0;
            minx = 999999999;
            miny = 999999999;
            DFS(i);

            ans = min(ans, (maxx - minx) * 2 + (maxy - miny) * 2);
        }
    }

    cout << ans << endl;
}