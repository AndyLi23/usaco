#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)


int main() {
    //graph implemented with a map-------------
    map<int, vector<int> > graph;
    
    //number of nodes
    int N = 4;

    //initialize
    FOR(i, N) {
        graph[i] = vector<int>();
    }
    //------------------------------------


    //example of implementation
    graph[0].push_back(5);
}