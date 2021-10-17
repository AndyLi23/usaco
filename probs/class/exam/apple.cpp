#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 1e5+5;

int C, N, PB, PA1, PA2, cur, a, b, c;

bool seen[2][MAXN];
int dist[2][MAXN];

//IMPLEMENTATION 1---

struct Edge {
    int weight, dest;
    bool operator<(const Edge &e) {
        if(weight==e.weight) return dest<e.dest;
        else return weight<e.weight;
    }
};

priority_queue<pair<int, int> > q;

void djikstras(int src, vector<Edge> graph[], int m) {
    FOR2(i, 1, N+1) {
        dist[m][i] = INT_MAX;
    }
    dist[m][src] = 0;
    q.push({0, src});

    while(!q.empty()) {
        cur = q.top().second;
        q.pop();

        if(seen[m][cur]) continue;
        seen[m][cur] = true;

        for(Edge u : graph[cur]) {
            if(dist[m][cur]+u.weight < dist[m][u.dest]) {
                dist[m][u.dest] = dist[m][cur] + u.weight;
                q.push({-dist[m][u.dest], u.dest});
            }
        }
    }
}



int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> C >> N >> PB >> PA1 >> PA2;

    vector<Edge> graph[MAXN];

    FOR(i, C) {
        cin >> a >> b >> c;
        graph[a].pb({c, b});
        graph[b].pb({c, a});
    }

    djikstras(PB, graph, 0);
    djikstras(PA1, graph, 1);

    cout << min(dist[0][PA2], dist[0][PA1]) + dist[1][PA2] << endl;
}