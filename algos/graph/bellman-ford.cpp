#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N, M, a, b, cur;
long long dist[5000];
bool seen[5000][2];
vector<int> adj[2500], adj2[2500];


//dfs for cycles
void dfs(int src, vector<int> graph[], int t) {
    if(!seen[src][t]) {
        seen[src][t] = true;
        FOR(k, graph[src].size()) {
            dfs(graph[src][k], graph, t);
        }
    }
}

long long BellmanFord(int source, vector<tuple<int, int, int> > e) {

    FOR(i, N) {
        dist[i] = (long long) 1e16;
    }

    dist[source] = 0;

    FOR(i, N) {
        for(auto [a,b,w] : e) {
            if((long long) dist[b] > (long long) dist[a] + (long long) w) {
                dist[b] = (long long) dist[a] + (long long) w;
                if(i == N-1 && seen[b][0] && seen[b][1]) {
                    //detect cycles on path from source to N-1
                    return -1;
                }
            }
        }
    }

    return dist[N - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> M;

    vector<tuple<int, int, int> > e;

    FOR(i, M) {
        cin >> a >> b >> cur;
        a--; b--;
        e.push_back({a, b, -cur});
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }

    dfs(0, adj, 0);
    dfs(N - 1, adj2, 1);
    cout << BellmanFord(0, e) << endl;
}