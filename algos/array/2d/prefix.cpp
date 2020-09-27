#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[10000][10000];

int main() {
    int N = 20;
    int M = 20;


    //prefix sum ------------
    int cur;

    for(int i = 0; i < N; ++i) {
        cur = 0;
        for(int j = 0; j < M; ++j) {
            cur += arr[i][j];
            arr[i][j] = cur;
        }
    }
    //---------------------

}    