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

int N, K, ans, x1, x2, y_1, y2;
int arr[1005][1005];

void prefixSum() {
    int cur;

    FOR(i, 1005) {
        cur = 0;
        FOR(j, 1005) {
            cur += arr[i][j];
            if(cur == K) {
                ans++;
            }
        }
    }
}

int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> K;

    FOR(i, N) {
        cin >> x1 >> y_1 >> x2 >> y2;

        FOR2(j, x1, x2) {
            arr[j][y_1]++;
            arr[j][y2]--;
        }
    }

    prefixSum();

    cout << ans;
}