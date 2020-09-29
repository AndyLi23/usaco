#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;


//edge class and add function---------

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
//----------------

int main() {
    //graph implemented with a map-------------
    map<int, vector<Edge> > graph;
    
    //number of nodes
    int N = 4;

    //initialize
    for(int i = 0; i < N; ++i) {
        graph[i] = vector<Edge>();
    }
    //------------------------------------


    //example of implementation
    graph[0].push_back(newEdge(2, 1));

}