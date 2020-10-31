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

long long N, K, M;

bool check(long long x) {
    long long tmp = 0;
    long long left = N;

    while(left > 0) {
        tmp++;
        if((left / x) < M) {
            return (left / M) + tmp <= K;
        }
        else
        {
            left -= (long long)(left / x);
        }
        if(tmp > K) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> K >> M;

    long long i = 1, j = 10000000000000, m = 0, ans = 0;

    while (i <= j) {
        m = (i+j)/2;

        if(check(m)) {
            ans = m;
            i = m + 1;
        } else {
            j = m - 1;
        }
    }

    cout << ans << endl;
}