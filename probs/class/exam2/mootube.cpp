#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 100000;

pair<int, pair<int, int> > conn[MAXN-1];
pair<int, int> queries[MAXN];

int parent[MAXN], size_[MAXN], temp[MAXN], ans[MAXN];

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

int N, Q;

bool comp(int i, int j) {
    return queries[i].first > queries[j].first;
}

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> Q;

    FOR(i, N-1) {
        cin >> conn[i].second.first >> conn[i].second.second >> conn[i].first;
        conn[i].second.first--;
        conn[i].second.second--;
    }

    sort(conn, conn + N - 1);

    FOR(i, N) {
        make_set(i);
    }

    FOR(i, Q) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].second--;
        temp[i] = i;
    }

    sort(temp, temp + Q, comp);

    int cur_conn = N-2;

    FOR(cur_q, Q) {
        int to_add = queries[temp[cur_q]].first;

        while(cur_conn >= 0 && conn[cur_conn].first >= to_add) {
            union_sets(conn[cur_conn].second.first, conn[cur_conn].second.second);
            cur_conn--;
        }

        ans[temp[cur_q]] = size_[find_set(queries[temp[cur_q]].second)] - 1;
    }

    FOR(i, Q) {
        cout << ans[i] << endl;
    }
}