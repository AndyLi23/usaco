#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); (i)++)


int arr[100000];
int N;


//sliding window--------------
void slidingWindow() {
    int sum = 0;

    int window_l = 5;

    FOR(i, window_l) {
        sum += arr[i];
    }

    FOR2(i, window_l, N) {
        //do something with sum

        sum += arr[i];
        sum -= arr[i-window_l];
    }
}
//-------------------------


//sliding window for sorted vector
void s(int maxlen) {
    int i, j=0;
    FOR(i, N) {
        while (j<N && arr[j]-arr[i]<=maxlen-1) {
            //i is lower, j is upper, everything in between
            j++;
        }
    }
}


int main() {
    
    N = 100;
    
    FOR(i, N) {
        arr[i] = i;
    }

    slidingWindow();
}