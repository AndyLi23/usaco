#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 2e5;

vector<int> graph[MAXN];
int ord[MAXN][2];

int cnt = 0;
void dfs(int x) {
    ord[x][0] = cnt++;
    for(auto y : graph[x]) {
        if(y != x) dfs(y);
    }
    ord[x][1] = cnt++;
}

bool isAncestor(int a, int b) {
    //returns true if a is ancestor of b or equal to b
    return ord[a][0] <= ord[b][0] && ord[a][1] >= ord[b][1];
}