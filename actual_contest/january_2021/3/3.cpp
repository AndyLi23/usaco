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

int N, arr[1000][1000], maxRows[1000], maxCols[1000], temp;

int main() {
    //freopen("3.in", "r", stdin);
    //freopen("3.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        FOR(j, N) {
            cin >> arr[i][j];
        }
    }

    FOR(i, N) {
        temp = 0;
        for (int j = 0; j < N; j+=2) {
            temp += arr[i][j];
        }
        maxRows[i] = temp;
        temp = 0;
        for (int j = 1; j < N; j+=2) {
            temp += arr[i][j];
        }
        maxRows[i] = max(maxRows[i], temp);
    }

    FOR(j, N) {
        temp = 0;
        for (int i = 0; i < N; i+=2) {
            temp += arr[i][j];
        }
        maxCols[j] = temp;
        temp = 0;
        for (int i = 1; i < N; i+=2) {
            temp += arr[i][j];
        }
        maxCols[j] = max(maxCols[j], temp);
    }

    int ans = 0, ans2 = 0;
    FOR(i, N) {
        ans += maxRows[i];
        ans2 += maxCols[i];
    }

    cout << max(ans, ans2) << endl;
}