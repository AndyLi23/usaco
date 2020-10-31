#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N, M, temp1, temp2;

map<int, vector<int> > graph;

set<int> left_;
bool left__[3005];
int seen[3005];
int cur1;

int DFS(int cur) {
    if(seen[cur] == cur1) {
        return 0;
    }
    seen[cur] = cur1;


    int ans = 1;
    FOR(i, graph[cur].size()) {
        if(!left__[graph[cur][i]]) {
            ans += DFS(graph[cur][i]);
        }
    }
    return ans;
}

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M;

    FOR(i, M) {
        cin >> temp1 >> temp2;

        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }

    FOR(i, N) {
        left_.insert(i+1);
    }

    FOR(i, N) {
        cur1++;

        if(DFS(*left_.begin()) == N-i) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        cin >> temp1;

        left_.erase(temp1);
        left__[temp1] = true;
    }
}