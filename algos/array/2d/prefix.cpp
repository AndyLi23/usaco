#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)


int arr[10000][10000];


int N, M;

//prefix sum ------------

void prefixSum() {
    int cur;

    FOR(i, N) {
        cur = 0;
        FOR(j, N) {
            cur += arr[i][j];
            arr[i][j] = cur;
        }
    }
}

//---------------------

int main() {
    N = 20;
    M = 20;

    prefixSum();

}    