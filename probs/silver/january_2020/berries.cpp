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

int N, K, ans, m, mod;
int berries[1000];

bool cmp(int a, int b) {
    return a % mod > b % mod;
}

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> K;
    FOR(i, N) {
        cin >> berries[i];
        m = max(m, berries[i]);
    }

    FOR2(i, 1, m+1) {
        int k = 0;
        FOR(j, N) {
            k += berries[j]/i;
        }
        if(k < K/2) {
            break;
        } else if (k >= K) {
            ans = max(ans, i * (K / 2));
        } else {
            mod = i;
            sort(berries, berries + N, cmp);

            int cur = i * (k - ((K + 1) / 2));
            FOR(j, K/2 - (k - ((K + 1) / 2))) {
                cur += berries[j] % i;
            }

            ans = max(ans, cur);
        }
    }

    cout << ans << endl;
}