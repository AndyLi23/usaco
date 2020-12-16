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

long long N, M;
pair<long long, long long> intervals[100000], temp;

bool check(long long m) {
    long long curPos = -1000000000, count = 0;
    FOR(i, M) {
        if(curPos + m <= intervals[i].first) {
            curPos = intervals[i].first;
            count++;
        } else if (curPos + m <= intervals[i].second) {
            curPos = curPos + m;
            count++;
        }
        while(curPos + m <= intervals[i].second) {
            curPos = curPos + m;
            count++;
            if(count >= N) {
                return true;
            }
        }
    }
    return (count >= N);
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M;

    FOR(i, M) {
        cin >> temp.first >> temp.second;
        intervals[i] = temp;
    }

    sort(intervals, intervals + M);

    long long i = 1;
    long long j = intervals[M-1].second - intervals[0].first;
    long long m, ans;

    //find minimum value that works (to find maximum, reverse j and i)

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