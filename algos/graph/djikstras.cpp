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


int N, min_n, min_ind, u;

int seen[100000];
int dist[100000];

int minDist() {
    min_n = INT_MAX;
    FOR(i, N) {
        if(dist[i] < min_n && seen[i] == 0) {
            min_n = dist[i];
            min_ind = i;
        }
    }
    return min_ind;
}

//IMPLEMENTATION 1---

int getDist(vector<Edge> graph[], int origin, int target) {
    FOR(i, graph[origin].size()) {
        if(graph[origin][i].dest == target) {
            return graph[origin][i].weight;
        }
    }
    return 0;
}

void djikstras(int src, vector<Edge> graph[]) {
    FOR(i, N) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;


    FOR(i, N) {
        u = minDist();

        seen[u] = 1;

        FOR(v, N) {
            if(getDist(graph, u, v) > 0 && seen[v] == 0 && dist[v] > dist[u]+getDist(graph, u, v)) {
                dist[v] = dist[u]+getDist(graph, u, v);
            }
        }
    }

}

//ALTERNATE--------

int graph2[100000][100000];

void djikstras2(int src) {
    FOR(i, N) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    FOR(i, N) {
        u = minDist();

        seen[u] = 1;

        FOR(v, N) {
            if(graph2[u][v] > 0 && seen[v] == 0 && dist[v] > dist[u]+graph2[u][v]) {
                dist[v] = dist[u]+graph2[u][v];
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


    //alternate----------

    FOR(i, N) {
        FOR(j, graph[i].size()) {
            graph2[i][graph[i][j].dest] = graph[i][j].weight;
        }
    }

    djikstras2(0);

    FOR(i, N) {
        cout << dist[i] << " ";
    }

    //------------------------------------
    
}