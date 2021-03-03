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

int N, M, a, b, group[200005], ans[200005], cur;
vector<int> adm[200005], group_list[200005];

queue<int> q;

void merge(int b, int a) {
    a = group[a];
    b = group[b];

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
    //use cin >> and cout <<

    cin >> N >> M;

    FOR(i, M) {
        cin >> a >> b;
        a--;
        b--;
        adm[a].push_back(b);
    }

    FOR(i, N) {
        group[i] = i;
        group_list[i].push_back(i);

        if(adm[i].size() > 1) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        cur = q.front();

        if(adm[cur].size() > 1) {
            a = adm[cur].back();
            adm[cur].pop_back();

            if(group[a] != group[adm[cur].back()]) {
                merge(a, adm[cur].back());
            }
        }
        else
        {
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