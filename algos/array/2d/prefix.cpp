#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[10000][10000];

int N, M;

//prefix sum ------------

void prefixSum() {
    int cur;

    for(int i = 0; i < N; ++i) {
        cur = 0;
        for(int j = 0; j < M; ++j) {
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