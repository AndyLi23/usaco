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

int N, M, f, t;
string temp;
int seen[100005], types[100005], groups[100005];

unordered_map<int, vector<int> > graph;

void dfs(int cur, int type, int groupnum) {
    if(!seen[cur]) {
        if (types[cur] == type) {
            seen[cur] = 1;
            groups[cur] = groupnum;
            FOR(i, graph[cur].size()) {
                dfs(graph[cur][i], type, groupnum);
            }
        }
    }
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M;

    cin >> temp;

    FOR(i, N) {
        types[i] = (temp[i] == 'H');
    }

    FOR(i, N-1) {
        cin >> f >> t;
        graph[f-1].push_back(t-1);
        graph[t-1].push_back(f-1);
    }

    int g = 1;

    FOR(i, N) {
        if(!seen[i]) {
            dfs(i, types[i], g);
            g++;
        }
    }

    FOR(i, M) {
        cin >> f >> t >> temp;
        if(groups[f-1] != groups[t-1]) {
            cout << 1;
        } else {
            cout << ((int)types[f - 1] == ((int)(temp == "H")));
        }
    }
    cout << endl;
}