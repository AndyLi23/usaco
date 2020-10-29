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

int N, ans, cur;

int x[200], y[200], b[200];
int seen[200];
unordered_map<int, vector<int>> graph;

int DFS(int origin) {
    if(seen[origin] < cur) {
        seen[origin] = cur;
        int temp = 1;
        FOR(i, graph[origin].size()) {
            temp += DFS(graph[origin][i]);
        }
        return temp;
    }
    return 0;
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> x[i] >> y[i] >> b[i];
    }

    FOR(i, N) {
        FOR(j, N) {
            if(i != j) {
                if((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) <= b[i]*b[i]) {
                    graph[i].push_back(j);
                }
            }
        }
    }

    FOR(i, N) {
        cur++;
        ans = max(ans, DFS(i));
    }

    cout << ans << endl;
}