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

int N, M, ans;
string cow_prefs[100005];
map<int, vector<int> > m;
int cow1[100005];
int cow2[100005];
bool seen[100005];
bool seenn[100005];

void DFS(int cow) {
    if(!seen[cow]) {
        seen[cow] = true;
        seenn[cow1[cow]] = true;
        seenn[cow2[cow]] = true;
        FOR(i, m[cow1[cow]].size())
        {
            DFS(m[cow1[cow]][i]);
        }
        FOR(i, m[cow2[cow]].size()) {
            DFS(m[cow2[cow]][i]);
        }
    }
}

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M;

    FOR(i, M) {
        cin >> cow_prefs[i] >> cow1[i] >> cow2[i];
        m[cow1[i]].push_back(i);
        m[cow2[i]].push_back(i);
    }

    FOR(i, M) {
        if(!seen[i]) {
            ans++;
            DFS(i);
        }
    }

    cout << 1;
    FOR(i, ans) {
        cout << 0;
    }
    FOR2(i, 1, N+1) {
        if(!seenn[i]) {
            cout << 0;
        }
    }
    cout << endl;
}