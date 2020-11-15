#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N;
int x[1000], y[1000];

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

class myComparator { public: 
    int operator() (const Edge& e1, const Edge& e2) { 
        return e1.weight > e2.weight; 
    } 
}; 

int seen[1000];
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
            ans = max(ans, cost);
            seen_num++;

            FOR(i, graph[cur].size()) {
                pq.push(graph[cur][i]);
            }
        }
    } 
    return ans;
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> x[i] >> y[i];
    }

    map<int, vector<Edge> > graph;
    int dist;

    FOR(i, N) {
        FOR2(j, i+1, N) {
            dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            graph[i].push_back(newEdge(dist, j));
            graph[j].push_back(newEdge(dist, i));
        }
    }

    cout << kruskals(graph) << endl;
}