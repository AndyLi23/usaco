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

int N;
long long T;
pair<long long, long long> cows[100000];

int main() {
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> T;

    FOR(i, N) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows, cows + N);

    long long prev = cows[N - 1].first + cows[N-1].second * T;
    int ans = N;

    FOR2R(i, N-2, 0) {
        long long temp = cows[i].first + cows[i].second * T;

        if(temp >= prev) {
            ans--;
        } else {
            prev = temp;
        }
    }

    cout << ans << endl;
}