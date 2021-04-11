#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N, cost[100000], groups[200005], temp[100000][4];

int a, b, c, d, cur;
unordered_map<int, vector<int> > m;





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

class myComparator { public: int operator() (const Edge& e1, const Edge& e2) { return e1.weight > e2.weight; } }; 
int seen[100000];
int seen_num = 0;

priority_queue<Edge, vector<Edge>, myComparator> pq;


int prims(unordered_map<int, vector<Edge> > graph) {
    pq.push(newEdge(0, cur));

    int ans = 0;
    int cost, current;
    Edge temp;

    while (pq.empty() == false && seen_num < cur) {
        temp = pq.top();
        pq.pop();

        cost = temp.weight;
        current = temp.dest;

        if(seen[current] == 0) {
            seen[current] = 1;
            ans += cost;
            seen_num++;

            FOR(i, graph[current].size()) {
                pq.push(graph[current][i]);
            }
        }
    } 
    return ans;
}






void dfs(int cur, int group) {
    if(!groups[cur]) {
        groups[cur] = group;
        FOR(i, m[cur].size()) {
            dfs(m[cur][i], group);
        }
    }
}

int main() {
    //freopen("2.in", "r", stdin);
    //freopen("2.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> cost[i];
        cin >> a >> b >> c >> d;

        m[a].push_back(b);
        m[b].push_back(a);
        m[c].push_back(d);
        m[d].push_back(c);

        temp[i][0] = a;
        temp[i][1] = b;
        temp[i][2] = c;
        temp[i][3] = d;
    }

    FOR2(i, 1, 2*N+1) {
        if(!groups[i]) {
            cur++;
            dfs(i, cur);
        }

        //cout << groups[i] << " ";
    }


    unordered_map<int, vector<Edge> > graph;

    FOR(i, N) {
        if(groups[temp[i][0]] != groups[temp[i][3]]) {
            graph[groups[temp[i][0]]].push_back(newEdge(cost[i], groups[temp[i][3]]));
            graph[groups[temp[i][3]]].push_back(newEdge(cost[i], groups[temp[i][0]]));
        }
    }

    cout << prims(graph) << endl;




}