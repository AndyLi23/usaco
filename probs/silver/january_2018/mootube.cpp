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

map<int, vector<Edge> > graph;
Edge temp;
int N, Q, from, to, weight, seen[5005], seenCnt, start, k;


int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> Q;

    FOR(i, N-1) {
        cin >> from >> to >> weight;

        graph[from].push_back(newEdge(weight, to));
        graph[to].push_back(newEdge(weight, from));
    }

    FOR(i, Q) {
        cin >> k >> start;
        
        queue <int> q;
        int cur, ans=0;
        seenCnt++;

        q.push(start);

        while(!q.empty()) {
            cur = q.front();
            q.pop();

            ans++;

            FOR(i, graph[cur].size()) {
                if(seen[graph[cur][i].dest] != seenCnt && graph[cur][i].weight >= k) {
                    q.push(graph[cur][i].dest);
                    seen[cur] = seenCnt;
                }
            }
        }

        cout << ans - 1 << endl;
    }
}