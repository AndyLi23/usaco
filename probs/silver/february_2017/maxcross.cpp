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

int N, K, B, temp, sum, ans, lights[100000];

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    //use cin >> and cout <<

    ans = 1000000;

    cin >> N >> K >> B;

    FOR(i, B) {
        cin >> temp;
        lights[temp - 1] = 1;
    }

    FOR(i, K) {
        sum += lights[i];
    }

    ans = min(ans, sum);

    FOR2(i, K, N) {
        sum += lights[i];
        sum -= lights[i-K];

        ans = min(ans, sum);
    }

    cout << ans << endl;
}