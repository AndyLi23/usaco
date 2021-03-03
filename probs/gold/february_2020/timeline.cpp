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

int N, M, C, S[100000], a, b, x, graphcount[100000], cur;
vector<pair<int, int> > graph[100000];
queue<int> q;

int main() {
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M >> C;

    FOR(i, N) {
        cin >> S[i];
    }

    FOR(i, C) {
        cin >> a >> b >> x;
        a--;
        b--;
        graph[a].push_back(make_pair(b, x));
        graphcount[b]++;
    }

    FOR(i, N) {
        if(!graphcount[i]) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        cur = q.front();
        q.pop();

        FOR(i, graph[cur].size()) {

            S[graph[cur][i].first] = max(S[graph[cur][i].first], graph[cur][i].second + S[cur]);

            graphcount[graph[cur][i].first]--;
            if(!graphcount[graph[cur][i].first]) {
                q.push(graph[cur][i].first);
            }
        }
    }

    FOR(i, N) {
        cout << S[i] << endl;
    }
}