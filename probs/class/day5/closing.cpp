#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 2e5+5;

int parent[MAXN], size_[MAXN], a, b, open[MAXN];

void make_set(int v) {
    parent[v] = v;
    size_[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if(size_[a] < size_[b])
            swap(a, b);
        parent[b] = a;
        size_[a] += size_[b];
    }
}

int N, M;

vector<int> adj[MAXN];

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> M;

    FOR(i, M) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<int> l;
    vector<int> ans;

    FOR(i, N) {
        cin >> a;
        l.pb(a);
    }

    int cnt = 0;

    FOR2R(i, N-1, 0) {
        cnt++;
        open[l[i]] = true;
        make_set(l[i]);
        for(auto c : adj[l[i]]) {
            if(open[c]) union_sets(l[i], c);
        }

        ans.pb(size_[find_set(l[i])] == cnt);
    }

    FOR2R(i, N-1, 0) {
        if(ans[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
