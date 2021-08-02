#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)


//ALGORITHM FOR MINIMUM COST SPANNING TREE (ALL NODES ARE CONNECTED)

struct Edge {
    int weight, dest;
    bool operator<(const Edge &e) {
        if(weight==e.weight) return dest<e.dest;
        else return weight<e.weight;
    }
};


//ALGORITHM--------------------------------------------

int N;

int seen[100000];
int seen_num = 0;

class comp { public: bool operator() (Edge e1, Edge e2) { return e2 < e1; } };

priority_queue < Edge, vector<Edge>, comp> pq;

int prims(vector<Edge> graph[]) {
    pq.push(Edge{0, N-1});

    int ans = 0;
    int cost, cur;
    Edge temp;

    while (pq.empty() == false && seen_num < N) {
        temp = pq.top();
        pq.pop();

        cost = temp.weight;
        cur = temp.dest;

        if(seen[cur] == 0) {
            cout << cur << " " << cost << endl;
            seen[cur] = 1;
            ans += cost;
            seen_num++;

            FOR(i, graph[cur].size()) {
                pq.push(graph[cur][i]);
            }
        }
    } 
    return ans;
}
//--------------------------------------------



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
    //------------------------------------


    //ACTUAL ALGORITHM-----------------------------------------


    cout << prims(graph) << endl;

    //-----------------------------------------
}