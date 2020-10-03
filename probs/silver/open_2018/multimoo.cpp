#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define FOR(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define FOR2(i, a, b) for (int(i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for (int(i) = (b); (i) >= (a); --(i))

//RUNNING:
//g++ -O task.cpp

int N, ans1, ans2;
int arr[250][250];

int seen[250][250];
int seent_ = 1;

map<int, set<int> > m;

int DFS(int i, int j, int target) {
    if(i >= 0 && i < N && j >= 0 && j < N && seen[i][j] == 0) {
        if(arr[i][j] == target) {
            seen[i][j] = 1;
            return 1 + DFS(i+1, j, target) + DFS(i-1, j, target) + DFS(i, j+1, target) + DFS(i, j-1, target);
        } else {
            m[target].insert(arr[i][j]);
            return 0;
        }
    }
    return 0;
}

int DFS2(int i, int j, int target, int target2, int seent) {
    if(i >= 0 && i < N && j >= 0 && j < N && (arr[i][j] == target || arr[i][j] == target2) && seen[i][j] <= seent) {
        seen[i][j] = seent+1;
        return 1 + DFS2(i+1, j, target, target2, seent) + DFS2(i-1, j, target, target2, seent) + DFS2(i, j+1, target, target2, seent) + DFS2(i, j-1, target, target2, seent);
    }
    return 0;
}

int main()
{
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        FOR(j, N) {
            cin >> arr[i][j];
        }
    }

    FOR(i, N) {
        FOR(j, N) {
            ans1 = max(ans1, DFS(i, j, arr[i][j]));
        }
    }

    FOR(i, N) {
        FOR(j, N) {
            if(seen[i][j] == 1) {
                for (set<int>::iterator itr = m[arr[i][j]].begin(); itr != m[arr[i][j]].end(); ++itr) {
                    ans2 = max(ans2, DFS2(i, j, arr[i][j], *itr, seent_));
                    seent_++;
                }
            }
        }
    }

    cout << ans1 << endl << ans2 << endl;
    
}