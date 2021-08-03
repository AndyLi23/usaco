#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)

struct Edge {
    int weight, dest;
    bool operator<(const Edge &e) {
        if(weight==e.weight) return dest<e.dest;
        else return weight<e.weight;
    }
};

//DJIKSTRAS--------------------------------------------


int N, cur;

bool seen[100000];
int dist[100000];

//IMPLEMENTATION 1---


class comp { public: bool operator() (Edge e1, Edge e2) { return e2 < e1; } };

priority_queue<pair<int, int> > q;

void djikstras(int src, vector<Edge> graph[]) {
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

        for(Edge u : graph[cur]) {
            if(dist[cur]+u.weight < dist[u.dest]) {
                dist[u.dest] = dist[cur] + u.weight;
                q.push({-dist[u.dest], u.dest});
            }
        }
    }
}


//--------------------------------------------------



int main() {
    vector<Edge> graph[5];
    
    N = 5;

    FOR(i, N) {
        graph[i] = vector<Edge>();
    }

    graph[0].push_back(Edge{2, 4});
    graph[0].push_back(Edge{5, 3});
    graph[0].push_back(Edge{6, 1});

    graph[1].push_back(Edge{6, 0});
    graph[1].push_back(Edge{3, 2});

    graph[2].push_back(Edge{3, 1});
    graph[2].push_back(Edge{3, 3});
    graph[2].push_back(Edge{4, 4});

    graph[3].push_back(Edge{3, 2});
    graph[3].push_back(Edge{2, 4});
    graph[3].push_back(Edge{5, 0});

    graph[4].push_back(Edge{2, 0});
    graph[4].push_back(Edge{2, 3});
    graph[4].push_back(Edge{4, 2});
    
    
    
    //implementation 1------------------------------------

    djikstras(0, graph);

    FOR(i, N) {
        cout << dist[i] << " ";
    }
    
}