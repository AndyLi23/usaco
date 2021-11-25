#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 300;

int S, D, N, M, R[MAXN], DB[MAXN], DP[MAXN], i, j, t, dist[MAXN], cur;
bool seen[MAXN];
char C[MAXN];
vector<pair<int, int> > graph[MAXN];


priority_queue<pair<int, int> > q;

char color_at(int cur, int time) {
    if(time < R[cur]) {
        return C[cur];
    } else {
        time = (time - R[cur]) % (DB[cur] + DP[cur]);
        if(C[cur] == 'B') {
            if(time < DP[cur]) {
                return 'P';
            } else {
                return 'B';
            }
        } else {
            if(time < DB[cur]) {
                return 'B';
            } else {
                return 'P';
            }
        }
    }
}

int time_to_next(int cur, int time) {
    if(time < R[cur]) {
        return R[cur] - time;
    } else {
        time = (time - R[cur]) % (DB[cur] + DP[cur]);
        if(C[cur] == 'B') {
            if(time < DP[cur]) {
                return DP[cur] - time;
            } else {
                return DP[cur] + DB[cur] - time;
            }
        } else {
            if(time < DB[cur]) {
                return DB[cur] - time;
            } else {
                return DP[cur] + DB[cur] - time;
            }
        }
    }
}

void djikstras(int src, vector<pair<int, int> > graph[]) {
    FOR(i, N) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    q.push({0, src});

    while(!q.empty()) {
        cur = q.top().second;
        q.pop();

        if(seen[cur]) continue;
        seen[cur] = true;

        for(pair<int, int> u : graph[cur]) {

            int time = dist[cur];

            while(color_at(cur, time) != color_at(u.first, time)) {
                time += min(time_to_next(u.first, time), time_to_next(cur, time));
            }

            int new_dist = time + u.second;

            if(new_dist < dist[u.first]) {
                dist[u.first] = new_dist;

                q.push({-dist[u.first], u.first});
            }
        }
    }
}


int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> S >> D >> N >> M; S--; D--;

    FOR(i, N) {
        cin >> C[i] >> R[i] >> DB[i] >> DP[i];
    }

    FOR(k, M) {
        cin >> i >> j >> t; i--; j--;
        graph[i].pb({j, t});
        graph[j].pb({i, t});
    }

    djikstras(S, graph);

    cout << dist[D] << endl;
}