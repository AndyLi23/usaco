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

int N, x[1000], y[1000], sy[1000], sx[1000], belowLeft, belowRight, aboveLeft, aboveRight, ans;
map<int, bool> m;

bool cmpx(int i, int j) {
    return x[i] < x[j];
}

bool cmpy(int i, int j) {
    return y[i] < y[j];
}

int main() {

    cin >> N;

    FOR(i, N) {
        cin >> x[i] >> y[i];
        sy[i] = i;
        sx[i] = i;
    }

    sort(sx, sx + N, cmpx);
    sort(sy, sy + N, cmpy);
    ans = 10000;

    int i = 0;
    while(i < N) {
        int cur = x[sx[i]];
        int prev = i;
        while(i < N && x[sx[i]] == cur) {
            i++;
        }
        FOR2(n, prev, i) {
            m[sx[n]] = true;
        }

        aboveLeft = i;
        aboveRight = N - i;
        belowLeft = 0;
        belowRight = 0;

        int j = 0;

        while(j < N) {
            int cur = y[sy[j]];
            int prev = j;
            while(j < N && y[sy[j]] == cur) {
                j++;
            }
            FOR2(k, prev, j) {
                if(m[sy[k]]) {
                    belowLeft++;
                    aboveLeft--;
                } else {
                    belowRight++;
                    aboveRight--;
                }
            }
            ans = min(ans, max(belowLeft, max(belowRight, max(aboveLeft, aboveRight))));
        }
    }
    cout << ans << endl;
}