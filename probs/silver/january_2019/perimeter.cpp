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

int N, maxnum;
string temp;
bool arr[1000][1000];

map<int, int> areatoperim;

bool seen[1000][1000], seen2[1000][1000], cur;

int DFS(int i, int j) {
    if(i >= 0 && i < N && j >= 0 && j < N && arr[i][j] && seen[i][j] < cur) {
        seen[i][j] = cur;
        return 1 + DFS(i+1, j) + DFS(i-1, j) + DFS(i, j+1) + DFS(i, j-1);
    }
    return 0;
}

bool get(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N && arr[i][j];
}

int DFSP(int i, int j) {
    if(i >= 0 && i < N && j >= 0 && j < N && arr[i][j] && seen2[i][j] < cur) {
        seen2[i][j] = cur;
        int ans = 4;
        if(get(i+1, j)) {
            ans--;
            ans += DFSP(i + 1, j);
        }
        if(get(i-1, j)) {
            ans--;
            ans += DFSP(i - 1, j);
        }
        if(get(i, j+1)) {
            ans--;
            ans += DFSP(i, j + 1);
        }
        if(get(i, j-1)) {
            ans--;
            ans += DFSP(i, j - 1);
        }
        return ans;
    }
    return 0;
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> temp;
        FOR(j, N) {
            arr[i][j] = temp[j] == '#';
        }
    }
    cur = 1;

    FOR(i, N) {
        FOR(j, N) {
            if(seen[i][j] != 1 && arr[i][j]) {
                int tempp = DFS(i, j);
                if (tempp >= maxnum) {
                    maxnum = tempp;
                    if(areatoperim[tempp] == 0) {
                        areatoperim[tempp] = DFSP(i, j);
                    } else {
                        areatoperim[tempp] = min(areatoperim[tempp], DFSP(i, j));
                    }
                }
            }
        }
    }
    cout << maxnum << " " << areatoperim[maxnum] << endl;
}