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

int N, M, C;
int cows[100005];

bool check(int maxm) {
    int buses = 0;
    int cur = 0;
    int prev = 0;

    FOR(i, N) {
        //cout << buses << cur << prev << endl;
        if (cows[i] - prev > maxm || cur == 0)
        {
            buses++;
            cur = 1;
            prev = cows[i];
        }
        else
        {
            cur++;
            if(cur == C) {
                cur = 0;
            }
        }
    }

    //cout << maxm << " " << buses << endl;

    return buses <= M;
}

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M >> C;

    FOR(i, N) {
        cin >> cows[i];
    }

    sort(cows, cows + N);

    int i = 0, j = 1000000000, m, ans;
    while (i <= j) {
        m = (i+j)/2;

        if(check(m)) {
            ans = m;
            j = m - 1;
        } else {
            i = m + 1;
        }
    }

    cout << ans << endl;
}