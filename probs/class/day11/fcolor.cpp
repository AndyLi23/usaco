#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 2e5;

int N, M, group[200005], a, b, ans[200005];
vector<int> adm[200005], group_list[200005];

queue<int> q;

void merge(int a, int b) {
    a = group[a];
    b = group[b];

    if(group_list[a].size() > group_list[b].size()) {
        swap(a, b);
    }

    FOR(i, group_list[a].size()) {
        group[group_list[a][i]] = b;
        group_list[b].push_back(group_list[a][i]);
    }

    adm[b].insert(adm[b].end(), adm[a].begin(), adm[a].end());
    adm[a].clear();

    if(adm[b].size() > 1) {
        q.push(b);
    }
}

int main() {
    freopen("fcolor.in", "r", stdin);
    freopen("fcolor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> M;

    FOR(i, M) {
        cin >> a >> b;
        a--;
        b--;
        adm[a].pb(b);
    }

    FOR(i, N) {
        group[i] = i;
        group_list[i].pb(i);

        if(adm[i].size() > 1) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        a = q.front();

        if(adm[a].size() > 1) {
            b = adm[a].back();
            adm[a].pop_back();

            if(group[adm[a].back()] != group[b]) {
                merge(adm[a].back(), b);
            }
        } else {
            q.pop();
        }
    }

    int c = 0;

    FOR(i, N) {
        if(!ans[group[i]]) {
            c++;
            ans[group[i]] = c;
        }

        cout << ans[group[i]] << endl;
    }
}