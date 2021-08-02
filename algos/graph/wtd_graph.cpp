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
        if(weight==e.weight) return dest<e.dest;
        else return weight<e.weight;
    }
};
//----------------

int main() {
    //graph implemented with a vector-------------
    vector<Edge> graph[4];
    
    //number of nodes
    int N = 4;


    //example of implementation
    graph[0].push_back(Edge{2, 1});

}