#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)


//edge class and add function---------

struct Edge {
    int weight, dest;
    bool operator<(const Edge &e) {
        if(dest==e.dest) return weight<e.weight;
        else return dest<e.dest;
    }
};
//----------------

int main() {
    //graph implemented with a map-------------
    map<int, vector<Edge> > graph;
    
    //number of nodes
    int N = 4;


    //example of implementation
    graph[0].push_back(Edge{2, 1});

}