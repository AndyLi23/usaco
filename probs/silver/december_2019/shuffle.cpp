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

int N, temp;
map<int, int> graph;
int seen[100005], seen2[100005];
int ans;

void clear() {
    fill(seen, seen+100005, 0);
}

vector<int> DFS(int cur, int begin, vector<int> path) {
    if(seen[cur] == 0) {
        if(seen2[cur] != 0) {
            return vector<int>();
        }
        seen[cur] = 1;
        path.push_back(cur);

        return DFS(graph[cur], begin, path);

    } else {
        if(cur == begin) {
            return path;
        }
    }
    return vector<int>();
}

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR2(i, 1, N+1) {
        cin >> temp;
        graph[i] = temp;
    }

    FOR2(i, 1, N+1) {
        if(seen2[i] == 0) {
            clear();

            vector<int> path = DFS(i, i, vector<int>());
            ans += path.size();
            FOR(j, path.size()) {
                seen2[path[j]] = 1;
            }
        }
    }

    cout << ans << endl;


}