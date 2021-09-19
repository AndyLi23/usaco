#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
#define MAXN = 2e5;

int D, P, C, F, S, a, b, c;

int dist[250], ans;

struct Edge {
    int weight, dest;
    bool operator<(const Edge &e) {
        return weight < e.weight;
    }
};

vector<Edge> graph[250];

int bfs() {
    priority_queue<pair<int, int> > pq;
    pq.push({S, D});

    FOR(i, C) {
        dist[i + 1] = -1;
    }

    while(!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        dist[cur.first] = cur.second;

        for(auto Edge : graph[cur.first]) {
            if(dist[Edge.dest] < cur.second + Edge.weight) {
                pq.push({Edge.dest, cur.second + Edge.weight});
            } else if (dist[Edge.dest] < cur.second + Edge.weight) {
                return -1;
            }
        }
    }

    FOR(i, C) {
        ans = max(ans, dist[i + 1]);
    }

    return ans;
}

int main() {
    freopen("jobhunt.in", "r", stdin);
    freopen("jobhunt.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> D >> P >> C >> F >> S;

    FOR(i, P) {
        cin >> a >> b;
        graph[a].pb({D, b});
    }

    FOR(i, F) {
        cin >> a >> b >> c;
        graph[a].pb({D - c, b});
    }

    cout << bfs() << endl;
}