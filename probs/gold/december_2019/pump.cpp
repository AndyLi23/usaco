#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N, M, a, b, c, f;
map<int, vector<int> > graph;
map<pair<int, int>, int> cost, flow;

vector<int> flows;

int djikstras(int source, int destination, int flowmin) {
    map<int, int> dist;
    set<pair<int, int> > visited;

    visited.insert(make_pair(0, source));

    while(!visited.empty()) {
        int cur = visited.begin()->second;
        visited.erase(visited.begin());

        if(cur == destination) {
            return dist[cur];
        }

        FOR(i, graph[cur].size()) {
            int j = graph[cur][i];

            if(flow[make_pair(cur, j)] >= flowmin) {
                if(dist.count(j) == 0 || dist[j] > dist[cur] + cost[make_pair(cur, j)]) {
                    dist[j] = dist[cur] + cost[make_pair(cur, j)];
                    visited.insert(make_pair(dist[j], j));
                }
            }
        }
    }

    return -1;
}

int main() {
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M;

    FOR(i, M) {
        cin >> a >> b >> c >> f;
        graph[a].push_back(b);
        graph[b].push_back(a);

        cost[make_pair(a, b)] = cost[make_pair(b, a)] = c;
        flow[make_pair(a, b)] = flow[make_pair(b, a)] = f;

        flows.push_back(f);
    }

    long long best_num = 0, best_den = 1, cur_den, cur_num;

    FOR(i, flows.size()) {
        cur_num = flows[i];

        cur_den = djikstras(1, N, cur_num);
        if(cur_den != -1 && cur_num * best_den > best_num * cur_den) {
            best_den = cur_den;
            best_num = cur_num;
        }
    }

    cout << best_num * 1000000LL / best_den << endl;
}