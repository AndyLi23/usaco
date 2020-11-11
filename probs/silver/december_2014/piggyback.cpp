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

int B, E, P, N, M, t1, t2, seen[40005], D[3][40005];
unordered_map<int, vector<int> > graph;

void DFS(int cur, int dist, int m, int n) {
    queue<pair<int, int> > q;
    q.push(make_pair(cur, dist));
    while(!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();

        if(seen[temp.first] < m) {
            seen[temp.first] = m;
            D[n][temp.first] = temp.second;
            FOR(i, graph[temp.first].size()) {
                q.push(make_pair(graph[temp.first][i], temp.second+1));
            }
        }
    }
}

int main() {
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
    //use cin >> and cout <<

    cin >> B >> E >> P >> N >> M;

    FOR(i, M) {
        cin >> t1 >> t2;
        graph[t1].push_back(t2);
        graph[t2].push_back(t1);
    }

    DFS(1, 0, 1, 0);
    DFS(2, 0, 2, 1);
    DFS(N, 0, 3, 2);

    int ans = 1000000000;
    FOR2(i, 1, N + 1) {
        ans = min(ans, D[0][i] * B + D[1][i] * E + D[2][i] * P);
    }
    cout << ans << endl;
}