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

int N, g[20][20];
int dir[8] = {1, 0, 0, 1, -1, 0, 0, -1};
string s;

bool seen[20][20][4][20][20][4];

class Edge {
    public:
    int d1, d2, cnt;
    pair<int, int> p1, p2;
};

Edge edge;

Edge newEdge(pair<int, int> p1, int d1, pair<int, int> p2, int d2, int cnt) {
    edge.p1 = p1;
    edge.d1 = d1;
    edge.p2 = p2;
    edge.d2 = d2;
    edge.cnt = cnt;

    return edge;
}

Edge cur, next_;
queue<Edge> q;

pair<int, int> t, goal;

pair<int, int> getNext(pair<int, int> p, int d) {
    t = p;
    t.first += dir[2 * d];
    t.second += dir[2 * d + 1];

    if(t.first < 0 || t.first > N-1 || t.second < 0 || t.first > N-1 || g[t.first][t.second] == 1 || p == goal) {
        return p;
    } else {
        return t;
    }
}

int main() {
    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);

    cin >> N;
    FOR(i, N) {
        cin >> s;
        FOR(j, N) {
            if(s[j] == 'H') {
                g[N-i-1][j] = 1;
            }
        }
    }

    goal = make_pair(N - 1, N - 1);

    seen[0][0][0][0][0][1] = true;

    Edge root = newEdge(make_pair(0, 0), 0, make_pair(0, 0), 1, 0);
    q.push(root);

    while(!q.empty()) {
        cur = q.front();
        q.pop();

        if(cur.p1 == goal && cur.p2 == goal) {
            cout << cur.cnt << endl;
            break;
        }
        
        next_.p1 = getNext(cur.p1, cur.d1);
        next_.d1 = cur.d1;
        next_.p2 = getNext(cur.p2, cur.d2);
        next_.d2 = cur.d2;
        next_.cnt = cur.cnt + 1;

        if(!seen[next_.p1.first][next_.p1.second][next_.d1][next_.p2.first][next_.p2.second][next_.d2]) {
            seen[next_.p1.first][next_.p1.second][next_.d1][next_.p2.first][next_.p2.second][next_.d2] = true;
            q.push(next_);
        }
        next_.p1 = cur.p1;
        next_.d1 = (cur.d1 + 1) % 4;
        next_.p2 = cur.p2;
        next_.d2 = (cur.d2 + 1) % 4;
        if(!seen[next_.p1.first][next_.p1.second][next_.d1][next_.p2.first][next_.p2.second][next_.d2]) {
            seen[next_.p1.first][next_.p1.second][next_.d1][next_.p2.first][next_.p2.second][next_.d2] = true;
            q.push(next_);
        }
        next_.d1 = (cur.d1 + 3)%4;
        next_.d2 = (cur.d2 + 3)%4;
        if(!seen[next_.p1.first][next_.p1.second][next_.d1][next_.p2.first][next_.p2.second][next_.d2]) {
            seen[next_.p1.first][next_.p1.second][next_.d1][next_.p2.first][next_.p2.second][next_.d2] = true;
            q.push(next_);
        }

    }
}