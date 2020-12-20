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

int N, f, t, ans;
unordered_map<int, vector<int> > map;
int seen[100005];

int nextPowerOf2(int target)   
{
    int count = 0;
    int n = 1;
    while(n < target) {
        n *= 2;
        count++;
    }
    return count;
}

void dfs(int cur) {
    int temp = 0;
    FOR(i, map[cur].size()) {
        if(!seen[map[cur][i]]) {
            temp++;
        }
    }
    ans += temp;
    //cout << cur << temp << endl;
    ans += nextPowerOf2(temp+1);
    FOR(i, map[cur].size()) {
        if(!seen[map[cur][i]]) {
            seen[map[cur][i]] = 1;
            dfs(map[cur][i]);
        }
    }
}

int main() {
    //comment out for submission
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N-1) {
        cin >> f >> t;
        map[f].push_back(t);
        map[t].push_back(f);
    }

    seen[1] = 1;
    dfs(1);

    cout << ans << endl;
}