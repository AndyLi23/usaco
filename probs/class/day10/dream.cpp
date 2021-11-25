#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 2e5;

int N, M, maze[1000][1000];
int seen[10000005];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

struct State {
    int i, j, ld;
    bool oranges;
};

bool check(int i, int j, bool oranges) {
    return i >= 0 && j >= 0 && i < N && j < M && maze[i][j] && (oranges || maze[i][j] != 3);
}

int pack(State cur) {
    return (cur.oranges ? 2 : 1) + 2 * (cur.ld + 1) + 10 * cur.i + 10000 * cur.j;
}

int bfs() {
    queue<State> q;
    q.push({0, 0, -1, false});
    seen[pack(q.front())] = 0;

    while(!q.empty()) {
        State cur = q.front();
        q.pop();

        //cout << cur.i << " " << cur.j << endl;

        if(cur.i == N-1 && cur.j == M-1) {
            return seen[pack(cur)];
        }

        int col = maze[cur.i][cur.j];

        if (col == 4 && cur.ld != -1) {
            //purple tile
            if(check(cur.i + dx[cur.ld], cur.j + dy[cur.ld], false)) {
                int newcol = maze[cur.i + dx[cur.ld]][cur.j + dy[cur.ld]];
                State newstate = {cur.i + dx[cur.ld], cur.j + dy[cur.ld], cur.ld, newcol == 2};


                if (seen[pack(newstate)] != -1)
                    continue;

                seen[pack(newstate)] = seen[pack(cur)] + 1;
                q.push(newstate);
                continue;
            }
        }

        FOR(i, 4) {
            if(check(cur.i + dx[i], cur.j + dy[i], cur.oranges)) {
                int newcol = maze[cur.i + dx[i]][cur.j + dy[i]];

                State newstate = {cur.i + dx[i], cur.j + dy[i], i, ((cur.oranges || newcol == 2) && newcol != 4)};

                if(seen[pack(newstate)] != -1)
                    continue;
                 
                seen[pack(newstate)] = seen[pack(cur)] + 1;
                q.push(newstate);
            }
        }    
    }

    return -1;
}

int main() {
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> M;

    fill(seen, seen + 10000005, -1);

    FOR(i, N) {
        FOR(j, M) {
            cin >> maze[i][j];
        }
    }


    cout << bfs() << endl;
}