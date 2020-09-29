#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

int main() {
    //graph implemented with a map-------------
    map<int, vector<int> > graph;
    
    //number of nodes
    int N = 4;

    //initialize
    for(int i = 0; i < N; ++i) {
        graph[i] = vector<int>();
    }
    //------------------------------------


    //example of implementation
    graph[0].push_back(5);
}