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

int N, M, u, seen[10000], l, r, c, tracker[10000];

long long T, ans, total[10000], cows[10000], dist[10000];

class Edge {
    public:
        int weight;
        int dest;
};

Edge newEdge(int weight, int dest) {
    Edge edge = Edge();
    edge.weight = weight;
    edge.dest = dest;

    return edge;
}

struct State{
    int v;                                 //vertex
    long long w;                           //current distance
};
struct CompareState{
   bool operator()(State s1, State s2){
      return s1.w > s2.w;
   }
};

void djikstras(int src, unordered_map<int, vector<Edge> > graph) {
    FOR(i, N) {
        dist[i] = 2000000000;
    }
    dist[src] = 0;

    fill(begin(tracker), end(tracker), -1);

    priority_queue<State,vector<State>,CompareState> pq;
    State s {0,0};
    pq.push(s);

    while(!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        u = cur.v;

        seen[u] = 1;

        FOR(i, graph[u].size()) {
            Edge e = graph[u][i];
            int v = e.dest;
            if (!seen[v]) {
                long long newdis = dist[u] + e.weight;
                if(newdis < dist[v]) {
                    dist[v] = newdis;
                    tracker[v] = u;
                    State next {v, newdis};
                    pq.push(next);
                } else if (newdis == dist[v]) {
                    if(u < tracker[v]) {
                        dist[v] = newdis;
                        tracker[v] = u;
                        State next {v, newdis};
                        pq.push(next);
                    }
                }
            }
        }
    }
}

int main() {
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M >> T;
    FOR(i, N) {
        cin >> cows[i];
        total[i] = cows[i];
    }

    unordered_map<int, vector<Edge> > graph;

    FOR(i, M) {
        cin >> l >> r >> c;
        graph[l - 1].push_back(newEdge(c, r - 1));
        graph[r - 1].push_back(newEdge(c, l - 1));
    }

    djikstras(0, graph);

    FOR(i, N) {
        int cur = i;
        while(tracker[cur] != -1) {
            total[tracker[cur]] += cows[i];
            cur = tracker[cur];
        }
    }

    FOR(i, N) {
        ans = max(ans, total[i] * (dist[i] - T));
    }


    cout << ans << endl;
}