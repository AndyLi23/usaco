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

long long N, M, cows, ans, curInd, curVal;
vector<pair<long long, long long> > intervals;

bool check(int m) {
    cows = 0;

    curInd = 0;
    curVal = -m-1;
    while (curInd < M) {
        //cout << cows << " " << curInd << " " << curVal << endl;
        if (intervals[curInd].first - m >= curVal) {
            curVal = intervals[curInd].first;
            cows++;
        } else if (intervals[curInd].second >= curVal + m) {
            curVal += m;
            cows++;
        } else {
            curInd++;
        }

        if(cows >= N) {
            return true;
        }
    }
    return false;
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M;

    intervals = vector<pair<long long, long long> >(M);

    FOR(i, M) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    sort(intervals.begin(), intervals.end());

    long long i = 1;
    long long j = intervals[M-1].second - intervals[0].first;
    long long m;

    while(i <= j) {
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