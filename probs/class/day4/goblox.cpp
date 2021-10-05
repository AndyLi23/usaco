#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
#define MAXN = 2e5;

int N, M, a, b, c;

struct Edge {
    int weight, dest;
    bool operator<(const Edge &e) {
        if(dest==e.dest) return weight<e.weight;
        else return dest<e.dest;
    }
};

bool seen[200];
ll dist[200];
int pre[200];

//IMPLEMENTATION 1---


priority_queue<pair<int, int> > q;

ll djikstras(int src, vector<Edge> graph[]) {
    FOR(i, N) {
        dist[i] = LLONG_MAX;
    }
    dist[src] = 0;
    q.push({0, src});

    while(!q.empty()) {
        int cur = q.top().second;
        q.pop();

        if(seen[cur]) continue;
        seen[cur] = true;

        for(Edge u : graph[cur]) {
            if(dist[cur]+u.weight < dist[u.dest]) {
                dist[u.dest] = dist[cur] + u.weight;
                pre[u.dest] = cur;
                q.push({-dist[u.dest], u.dest});
            }
        }
    }

    return dist[N-1];
}

vector<Edge> graph[200];

ll ans_;

int main() {
    freopen("goblox.in", "r", stdin);
    freopen("goblox.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> M;
    FOR(i, M) {
        cin >> a >> b >> c; a--; b--;
        graph[a].pb({c, b});
        graph[b].pb({c, a});
    }

    ll temp = djikstras(0, graph);

    int cur = N-1;
    vector<int> path;
    path.pb(cur);
    while (cur != 0) {
        cur = pre[cur];
        path.pb(cur);
    }

    FOR(i, path.size()-1) {
        fill(seen, seen+N, 0);
        FOR(j, graph[path[i+1]].size()) {
            if(graph[path[i+1]][j].dest == path[i]) {
                graph[path[i+1]][j].weight *= 2;
                ans_ = max(ans_, djikstras(0, graph));
                graph[path[i+1]][j].weight /= 2;
                break;
            }
        }
    }

    cout << ans_ - temp << endl;
}