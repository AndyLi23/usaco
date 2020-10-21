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

int N, K, cur;

int arr[105][15];

int seen[105][15];

int DFS(int i, int j, int cur, int target) {
    if(i >= 0 && i < N && j >= 0 && j < 10 && arr[i][j] == target && seen[i][j] <= cur) {
        seen[i][j] = cur+1;
        return 1 + DFS(i+1, j, cur, target) + DFS(i-1, j, cur, target) + DFS(i, j+1, cur, target) + DFS(i, j-1, cur, target);
    }
    return 0;
}

int FILL(int i, int j, int cur, int target) {
    if(i >= 0 && i < N && j >= 0 && j < 10 && arr[i][j] == target) {
        arr[i][j] = 0;
        return FILL(i + 1, j, cur, target) + FILL(i - 1, j, cur, target) + FILL(i, j + 1, cur, target) + FILL(i, j - 1, cur, target);
    }
    return 0;
}

void dropDown() {
    FOR(j, 10) {
        vector<int> t;
        FOR2R(i, N - 1, 0) {
            if(arr[i][j] != 0) {
                t.push_back(arr[i][j]);
                arr[i][j] = 0;
            }
        }

        FOR(i, t.size()) {
            arr[N - i - 1][j] = t[i];
        }
    }
}

int main() {
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> K;

    string temp;

    FOR(i, N) {
        cin >> temp;
        FOR(j, 10) {
            arr[i][j] = (int) temp[j] - 48;
        }
    }

    bool good = true;

    while(good) {
        good = false;
        FOR(i, N) {
            FOR(j, 10) {
                if(arr[i][j] != 0 && DFS(i, j, cur, arr[i][j]) >= K) {
                    good = true;
                    FILL(i, j, cur, arr[i][j]);
                }
            }
            cur++;
        }

        dropDown();
    }

    FOR(i, N)
    {
        FOR(j, 10)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}