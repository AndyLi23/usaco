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

int N, M, a, b, width, temp;
unordered_map<int, int> m;
unordered_map<int, vector<pair<int, int> > > graph;

unordered_map<int, int> w_to_c;

bool seen[100000];


void DFS(int cur, int c, int minW) {
    if(!seen[cur]) {
        //cout << cur << endl;
        w_to_c[cur] = c;
        seen[cur] = true;
        FOR(i, graph[cur].size()) {
            if(graph[cur][i].second >= minW) {
                DFS(graph[cur][i].first, c, minW);
            }
        }
    }
}

bool check(int minW) {
    fill(seen, seen + N + 1, false);

    int cur = 1;
    FOR2(i, 1, N + 1) {
        if(!seen[i]) {
            DFS(i, cur, minW);
            cur++;
        }
    }

    FOR2(i, 1, N+1) {
        if(m[i] != i) {
            if(w_to_c[i] == 0 || w_to_c[m[i]] == 0) {
                return false;
            } else if (w_to_c[i] != w_to_c[m[i]]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M;
    FOR(i, N) {
        cin >> temp;
        m[temp] = i+1;
    }

    FOR(i, M) {
        cin >> a >> b >> width;
        graph[a].push_back(make_pair(b, width));
        graph[b].push_back(make_pair(a, width));
    }

    int i = 0, j = 1000000000, ans = 0;


    while (i <= j) {
        int mid = (i+j)/2;


        if(check(mid)) {
            ans = mid;
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }

    if(ans == 1000000000) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}