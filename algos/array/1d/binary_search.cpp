#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[100000];

int main() {
    
    int N = 10000;
    int target = 20;
    
    for(int i = 0; i < N; ++i) {
        arr[i] = i;
    }



    //binary search--------------
    int i = 0;
    int j = N;
    int m;
    int target = 20;

    while(i <= j) {
        m = (i+j)/2;

        if(m == target) {
            //do something
            break;
        } else if (m > target) {
            j = m-1;
        } else {
            i = m+1;
        }
    }
    //-------------------------
}