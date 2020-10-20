#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)


int arr[100000];
int N;


//binary search--------------
int binarySearch(int target) {
    int i = 0;
    int j = N;
    int m;

    while(i <= j) {
        m = (i+j)/2;

        if(m == target) {
            break;
        } else if (m > target) {
            j = m-1;
        } else {
            i = m+1;
        }
    }

    return m;
}
//-------------------------


//binary search for a check fuction-------------------------
bool check(int m) { return true; };

int binarySearch2() {
    int i = 0, j = 1000000000, m, ans;

    //find minimum value that works (to find maximum, reverse j and i)

    while (i <= j) {
        m = (i+j)/2;

        if(check(m)) {
            ans = m;
            j = m - 1;
        } else {
            i = m + 1;
        }
    }
}
//---------------------------------------------------------------------------

int main() {
    
    N = 10000;
    
    FOR(i, N) {
        arr[i] = i;
    }

    binarySearch(20);
}