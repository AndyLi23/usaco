struct Edge {
    int weight, dest;
    bool operator<(const Edge &e) {
        if(weight==e.weight) return dest<e.dest;
        else return weight<e.weight;
    }
};

struct State{
    int v;
    long long w;
};
struct CompareState{
   bool operator()(State s1, State s2){
      return s1.w > s2.w;
   }
};

void djikstras(int src, vector<Edge> graph[]) {
    FOR(i, N) {
        dist[i] = INT_MAX;
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
                    State next {v, newdis};
                    pq.push(next);
                }
            }
        }
    }
}