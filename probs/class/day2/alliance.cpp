#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 100005;

int N, M, a, b;
vector<int> graph[MAXN];
bool seen[MAXN];

int result = 1;

pair<int, int> dfs(int x) {
  if(seen[x]) return make_pair(0, 0);
  seen[x] = true;

  pair<int, int> ans(1, graph[x].size());
  for(auto i : graph[x]) {
        pair<int, int> tmp = dfs(i);
        ans.first += tmp.first;
        ans.second += tmp.second;
  }
  return ans;
}

int main() {
    freopen("alliance.in", "r", stdin);
    freopen("alliance.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> M;

    FOR(i, M) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    FOR2(i, 1, N+1) {
        if(!seen[i] && graph[i].size() > 0) {
            pair<int, int> ans = dfs(i);
            ans.second /= 2;
            if(ans.first == ans.second + 1) {
                result = (1ll * result * ans.first) % MOD;
            } else if(ans.first == ans.second) {
                result = (2 * result) % MOD;
            }
        }
    }

    cout << result << endl;
}