#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;


#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)

//RUNNING:
//g++ -O task.cpp


int N, M, to, from, ffrom, fto;
string farms;
char temp;
map<int, vector<int> > graph;

int node_to_group[100005];
int cur_g = 1;

void dfs(int cur, int group, char goal) {
    if(node_to_group[cur] == 0 && goal == farms[cur-1]) {
        node_to_group[cur] = group;

        FOR(j, graph[cur].size()) {
            dfs(graph[cur][j], group, goal);
        }
    }
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    cin >> N >> M;
    cin >> farms;

    FOR(i, N) {
        graph[i] = vector<int>();
    }

    FOR(i, N-1) {
         cin >> to >> from;

         graph[to].push_back(from);
         graph[from].push_back(to);
    }

    FOR(i, N) {
        if(node_to_group[i+1] == 0) {
            dfs(i+1, cur_g, farms[i]);
            cur_g++;
        }
    }

    FOR(i, M) {
        cin >> ffrom >> fto >> temp;

        if(node_to_group[ffrom] != node_to_group[fto]) {
            cout << 1;
        } else {
            cout << (farms[ffrom-1] == temp);
        }
    }

    cout << endl;

}