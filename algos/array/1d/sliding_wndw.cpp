#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[100000];
int N;


//sliding window--------------
void slidingWindow() {
    int sum = 0;

    int window_l = 5;

    for(int i = 0; i < window_l; ++i) {
        sum += arr[i];
    }

    for(int i = window_l; i < N; ++i) {
        //do something with sum

        sum += arr[i];
        sum -= arr[i-window_l];
    }
}
//-------------------------


int main() {
    
    N = 100;
    
    for(int i = 0; i < N; ++i) {
        arr[i] = i;
    }

    slidingWindow();
}