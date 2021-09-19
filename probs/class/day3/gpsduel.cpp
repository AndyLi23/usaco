#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 10005;

int N, M, a, b, p, q_;

struct Edge {
    int weight, dest;
    bool operator<(const Edge &e) {
        if(dest==e.dest) return weight<e.weight;
        else return dest<e.dest;
    }
};

vector<Edge> graphp[MAXN], graphq[MAXN], graph[MAXN];
vector<int> paths[MAXN];

bool seen[MAXN];
int dist[MAXN], pre[MAXN];

void djikstras(int src, vector<Edge> graph[]) {
    priority_queue<pair<int, int> > q;
    FOR(i, N) {
        dist[i+1] = INT_MAX;
        seen[i+1] = false;
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
}

int main() {
    freopen("gpsduel.in", "r", stdin);
    freopen("gpsduel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> M;

    FOR(i, M) {
        cin >> a >> b >> p >> q_;
        graphp[b].pb({p, a});
        graphq[b].pb({q_, a});
        paths[a].pb(b);
    }

    djikstras(N, graphp);
    FOR(i, N) {
        for(auto j : paths[i+1]) {
            if(j != pre[i+1]) {
                graph[i + 1].pb({1, j});
            } else {
                graph[i + 1].pb({0, j});
            }
        }
    }

    djikstras(N, graphq);

    FOR(i, N) {
        FOR(j, graph[i+1].size()) {
            if(graph[i+1][j].dest != pre[i+1]) {
                graph[i + 1][j].weight++;
            }
        }
    }

    djikstras(1, graph);
    cout << dist[N] << endl;
}