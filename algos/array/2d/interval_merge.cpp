#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); (i)++)


//sliding window--------------
vector<vector<int> > mergeIntervals(vector<vector<int> > intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int> >u_intervals;
    u_intervals.push_back(intervals[0]);
    int last = 0;
    FOR2(i, 1, intervals.size()) {
        if (intervals[i][0] <= u_intervals[last][1]) {
            u_intervals[last][1] = max(u_intervals[last][1], intervals[i][1]);
        } else {
            u_intervals.push_back(intervals[i]);
            last++;
        }
    }

    return u_intervals;
}
//-------------------------

int main() {

    vector<vector<int> > intervals;
    FOR(i, 5) {
        vector<int> temp;
        temp.push_back(i);
        temp.push_back(i+5);
        intervals.push_back(temp);
    }


    vector<vector<int> > u_intervals = mergeIntervals(intervals);
}