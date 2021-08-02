#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)

struct Edge {
    int weight, dest;
    bool operator<(const Edge &e) {
        if(weight==e.weight) return dest<e.dest;
        else return weight<e.weight;
    }
};

//BFS--------------------------------------------

int seen[100000];

void BFS(vector<Edge> graph[], int start) {
    queue <int> q;
    int cur;

    q.push(start);

    while(!q.empty()) {
        cur = q.front();
        q.pop();


        if(seen[cur] == 0) {
            cout << cur << " ";

            seen[cur] = 1;
            FOR(i, graph[cur].size()) {
                q.push(graph[cur][i].dest);
            }
        }
    }
}

int seen2[100000];

void DFS(vector<Edge> graph[], int cur) {
    if(seen2[cur] == 0) {
        seen2[cur] = 1;

        cout << cur << " ";

        FOR(i, graph[cur].size()) {
            DFS(graph, graph[cur][i].dest);
        }
    }
} 

//--------------------------------------------------

int N;

int main() {
    vector<Edge> graph[5];
    
    N = 5;

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
    
    
    //testing

    DFS(graph, 0);

    cout << endl;

    BFS(graph, 0);

    
}