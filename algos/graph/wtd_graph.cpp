#include <algorithm>
#include <iostream>
#include <vector>

//DONT FORGET THIS
#include <map>
//-------------


using namespace std;


//edge class---------
class Edge {
    public:
    int weight, dest;
};
//----------------

int main() {
    //graph implemented with a map-------------
    map<int, vector<Edge*> > graph;
    
    //number of nodes
    int N = 4;

    //initialize
    for(int i = 0; i < N; ++i) {
        graph[i] = vector<Edge*>();
    }
    //------------------------------------


    //example of implementation
    graph[0].push_back(new Edge());
    graph[0][0]->weight = 5;
    graph[0][0]->dest = 1;

    
}