#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 1e5+5;

int N, M, t[MAXN], a, b, ans[MAXN], q[MAXN][3], ord[MAXN][2];
vector<int> graph[MAXN];

vector<pair<int, int> > tStack[MAXN];
vector<int> curStack;
vector<int> todo[MAXN];

int cnt = 0;
void dfs(int x, int prev) {
    ord[x][0] = cnt++;
    for(auto y : graph[x]) {
        if(y != prev) dfs(y, x);
    }
    ord[x][1] = cnt++;
}

bool isAncestor(int a, int b) {
    return ord[a][0] <= ord[b][0] && ord[a][1] >= ord[b][1];
}

void dfs2(int x, int prev) {
    curStack.pb(x);
    tStack[t[x]].pb({x, curStack.size()-1});

    for(auto i : todo[x]) {

        if(tStack[q[i][2]].size()) {
            pair<int, int> y = tStack[q[i][2]].back();

            if(y.first == x) ans[i] = 1;
            else {
                if(!isAncestor(curStack[y.second+1], q[i][0] + q[i][1] - x)) ans[i] = 1;
            }

        }
    }

    for(auto y : graph[x]) {
        if(y != prev) dfs2(y, x);
    }

    curStack.pop_back();
    tStack[t[x]].pop_back();
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> M;
    FOR(i, N) cin >> t[i];

    FOR(i, N-1) {
        cin >> a >> b;
        graph[a - 1].pb(b - 1);
        graph[b - 1].pb(a - 1);
    }

    dfs(0, -1);

    FOR(i, M) {
        cin >> q[i][0] >> q[i][1] >> q[i][2];
        q[i][0]--;
        q[i][1]--;

        todo[q[i][0]].pb(i);
        todo[q[i][1]].pb(i);
    }

    dfs2(0, -1);

    FOR(i, M) {
        cout << ans[i];
    }
    cout << endl;
}