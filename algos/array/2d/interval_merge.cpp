#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main() {

    vector<vector<int> > intervals;
    for(int i = 0; i < 5; i++) {
        vector<int> temp;
        temp.push_back(i);
        temp.push_back(i+5);
        intervals.push_back(temp);
    }


    //sliding window--------------
    sort(intervals.begin(), intervals.end());

    vector<vector<int> >u_intervals;
    u_intervals.push_back(intervals[0]);
    int last = 0;
    for(int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= u_intervals[last][1]) {
            u_intervals[last][1] = max(u_intervals[last][1], intervals[i][1]);
        } else {
            u_intervals.push_back(intervals[i]);
            last++;
        }
    }

    //-------------------------
}