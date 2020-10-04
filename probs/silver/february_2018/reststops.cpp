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

int N, L, pv, gain, pv_x;

long long ans, RF, RB;

class Stop {
    public:
    int x, w;
};

Stop temp;
Stop stops[100000];

int main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    //use cin >> and cout <<

    cin >> L >> N >> RF >> RB;

    int gain = RF - RB;

    FOR(i, N) {
        temp = Stop();
        cin >> temp.x >> temp.w;
        stops[i] = temp;
    }

    pv = 0;

    FOR2R(i, N-1, 0) {
        if (stops[i].w <= pv) {
            stops[i].w = 0;
        } else {
            pv = stops[i].w;
        }
    }

    pv_x = 0;

    ans = 0;

    FOR(i, N) {
        if(stops[i].w != 0) {
            ans += (((long long) stops[i].x - (long long) pv_x)) * ((long long) gain) * ((long long) stops[i].w);
            pv_x = stops[i].x;
        }
    }

    cout << ans << "\n";
}