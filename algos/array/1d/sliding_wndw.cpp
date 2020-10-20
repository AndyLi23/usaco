#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); (i)++)


int arr[100000];
int N;
vector<int> v;

//sliding window--------------
void slidingWindow() {
    int sum = 0;

    int window_l = 5;

    FOR(i, window_l) {
        sum += arr[i];
    }

    FOR2(i, window_l, N) {
        sum += arr[i];
        sum -= arr[i-window_l];

        //do something with sum
    }
}
//-------------------------


//sliding window for sorted vector --------
void slidingWindowV(int maxlen) {
    int i, j=0, cur = 0;
    FOR(i, N) {
        while (j<N && v[j]-v[i]<=maxlen-1) {
            //i is lower, j is upper, everything in between
            //number of elements between = j-i+1
            cur += v[j];
            //cur is window sum
            j++;
        }
        cur -= v[i];
    }
}
//-----------------------------------------


int main() {
    
    N = 100;
    
    FOR(i, N) {
        v.push_back(i);
    }

    slidingWindowV(3);
}