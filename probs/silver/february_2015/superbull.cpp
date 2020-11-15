#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define FOR(i, n) for(long long (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(long long (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(long long (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

long long N;
long long teams[2000];



class Edge {
    public:
    long long weight, dest;
};

Edge newEdge(long long weight, long long dest) {
    Edge edge = Edge();
    edge.weight = weight;
    edge.dest = dest;

    return edge;
}

map<long long, vector<Edge> > graph;



//ALGORITHM--------------------------------------------

class myComparator 
{ 
public: 
    long long operator() (const Edge& e1, const Edge& e2) 
    { 
        return e1.weight < e2.weight; 
    } 
}; 

long long seen[2000];
long long seen_num = 0;

priority_queue<Edge, vector<Edge>, myComparator> pq;

long long kruskals(map<long long, vector<Edge> > graph) {
    pq.push(newEdge(0, N-1));

    long long ans = 0;
    long long cost, cur;
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

            FOR(i, graph[cur].size()) {
                pq.push(graph[cur][i]);
            }
        }
    } 
    return ans;
}

int main() {
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;
    FOR(i, N) {
        cin >> teams[i];
    }

    FOR(i, N) {
        FOR2(j, i+1, N) {
            graph[i].push_back(newEdge(teams[i] ^ teams[j], j));
            graph[j].push_back(newEdge(teams[j] ^ teams[i], i));
        }
    }

    cout << kruskals(graph) << endl;
}