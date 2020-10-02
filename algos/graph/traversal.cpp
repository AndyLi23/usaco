#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)


class Edge {
    public:
    int weight, dest;
};

Edge newEdge(int weight, int dest) {
    Edge edge = Edge();
    edge.weight = weight;
    edge.dest = dest;

    return edge;
}



//BFS--------------------------------------------

int seen[100000];

void BFS(map<int, vector<Edge> > graph, int start) {
    queue <int> q;
    int cur;

    q.push(start);

    while(!q.empty()) {
        cur = q.front();
        q.pop();


        if(seen[cur] == 0) {
            cout << cur << " ";

            seen[cur] = 1;
            for(int i = 0; i < graph[cur].size(); ++i) {
                q.push(graph[cur][i].dest);
            }
        }
    }
}

int seen2[100000];

void DFS(map<int, vector<Edge> > graph, int cur) {
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
    map<int, vector<Edge> > graph;
    
    N = 5;

    FOR(i, N) {
        graph[i] = vector<Edge>();
    }

    graph[0].push_back(newEdge(2, 4));
    graph[0].push_back(newEdge(5, 3));
    graph[0].push_back(newEdge(6, 1));

    graph[1].push_back(newEdge(6, 0));
    graph[1].push_back(newEdge(3, 2));

    graph[2].push_back(newEdge(3, 1));
    graph[2].push_back(newEdge(3, 3));
    graph[2].push_back(newEdge(4, 4));

    graph[3].push_back(newEdge(3, 2));
    graph[3].push_back(newEdge(2, 4));
    graph[3].push_back(newEdge(5, 0));

    graph[4].push_back(newEdge(2, 0));
    graph[4].push_back(newEdge(2, 3));
    graph[4].push_back(newEdge(4, 2));
    
    
    
    //testing

    DFS(graph, 0);

    cout << endl;

    BFS(graph, 0);

    
}