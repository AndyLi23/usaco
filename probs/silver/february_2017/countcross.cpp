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

int N, K, R, cur;
bool seen[105][105];

unordered_map<int, bool> cows;
unordered_map<int, int> groups;
unordered_map<int, unordered_map<int, bool> > roads;
pair<int, int> temp, temp1;

int hashpair(pair<int, int> p) {
    return p.first + p.second * 105;
}

int hashij(int i, int j) {
    return i + j * 105;
}

int DFS(int i, int j) {
    if(i > 0 && j > 0 && i <= N && j <= N && !seen[i][j]) {
        seen[i][j] = true;
        int hsh = hashij(i, j);
        int ans = 0;
        if (cows[hsh]) {
            ans++;
        }
        if(!roads[hsh][hashij(i+1, j)]) {
            ans += DFS(i + 1, j);
        }
        if(!roads[hsh][hashij(i-1, j)]) {
            ans += DFS(i - 1, j);
        }
        if(!roads[hsh][hashij(i, j+1)]) {
            ans += DFS(i, j+1);
        }
        if(!roads[hsh][hashij(i, j-1)]) {
            ans += DFS(i, j-1);
        }
        return ans;
    }
    return 0;
}

int main() {
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> K >> R;

    FOR(i, R) {
        cin >> temp.first >> temp.second >> temp1.first >> temp1.second;
        roads[hashpair(temp)][hashpair(temp1)] = true;
        roads[hashpair(temp1)][hashpair(temp)] = true;
    }

    FOR(i, K) {
        cin >> temp.first >> temp.second;
        cows[hashpair(temp)] = true;
    }

    FOR2(i, 1, N+1) {
        FOR2(j, 1, N+1) {
            if(!seen[i][j]) {
                //cout << DFS(i, j) << endl;
                groups[cur] = DFS(i, j);
                cur++;
            }
        }
    }

    int ans = 0;
    FOR(i, cur) {
        FOR2(j, i+1, cur) {
            ans += groups[i] * groups[j];
        }
    }

    cout << ans << endl;
}