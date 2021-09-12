#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
const int MOD = 1000000007;
const int MAXN = 1e5+5;

int N, K, a, b;
vector<int> graph[MAXN];
queue<pair<int, int> > q;
int distLeaf[MAXN], distStart[MAXN], ans;
bool seen[MAXN];

void dfsDistances(int cur, int par) {
    if(par != -1) {
        distStart[cur] = distStart[par] + 1;
    }
    bool isLeaf = true;
    for(auto i : graph[cur]) {
        if(par != i) {
            dfsDistances(i, cur);
            isLeaf = 0;
        }
    }
    if(isLeaf) q.push({cur, -1});
}

void bfsDistances() {
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if(!seen[cur.first]) {
            seen[cur.first] = true;

            if(cur.second != -1) {
                distLeaf[cur.first] = distLeaf[cur.second]+1;
            }

            for(auto i : graph[cur.first]) {
                if(i != cur.second) {
                    q.push({i, cur.first});
                }
            }
        }

    }
}

void dfsAnswer(int cur, int par) {
    if(par != -1) {
        if(distLeaf[cur] <= distStart[cur] && distLeaf[par] > distStart[par]) ans++;
    }
    for(auto i : graph[cur]) {
        if(i != par) dfsAnswer(i, cur);
    }
}

int main() {
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> K;

    FOR(i, N) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfsDistances(K, -1);
    bfsDistances();
    dfsAnswer(K, -1);

    cout << ans << endl;
}