#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[100000];

int main() {
    
    int N = 100;
    
    for(int i = 0; i < N; ++i) {
        arr[i] = i;
    }



    //sliding window--------------
    int sum = 0;

    int window_l = 5;

    for(int i = 0; i < window_l; ++i) {
        sum += arr[i];
    }

    for(int i = window_l; i < N; ++i) {
        //do something with sum
        //cout << sum << " ";


        sum += arr[i];
        sum -= arr[i-window_l];
    }
    //-------------------------
}