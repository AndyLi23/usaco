#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

//IMPORTANT IMPORT----------
#include <queue>
//-------------------------

using namespace std;

//ALGORITHM FOR MINIMUM COST SPANNING TREE (ALL NODES ARE CONNECTED)


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



//ALGORITHM--------------------------------------------
class myComparator 
{ 
public: 
    int operator() (const Edge& e1, const Edge& e2) 
    { 
        return e1.weight > e2.weight; 
    } 
}; 

int N;

int seen[100000];
int seen_num = 0;

priority_queue<Edge, vector<Edge>, myComparator> pq;


int kruskals(map<int, vector<Edge> > graph) {
    pq.push(newEdge(0, N-1));

    int ans = 0;
    int cost, cur;
    Edge temp;

    while (pq.empty() == false && seen_num < N) {
        temp = pq.top();
        pq.pop();

        cost = temp.weight;
        cur = temp.dest;

        if(seen[cur] == 0) {
            seen[cur] = 1;
            ans += cost;
            seen_num++;

            for(int i = 0; i < graph[cur].size(); ++i) {
                pq.push(graph[cur][i]);
            }
        }
    } 
    return ans;
}
//--------------------------------------------



int main() {
    map<int, vector<Edge> > graph;
    
    N = 5;

    for(int i = 0; i < N; ++i) {
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
    //------------------------------------


    //ACTUAL ALGORITHM-----------------------------------------


    cout << kruskals(graph) << endl;

    //-----------------------------------------
}