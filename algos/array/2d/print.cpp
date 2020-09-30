#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[10000][10000];

int N, M;

//print array -----------------
void print2d() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
//----------------------------

int main() {
    N = 20;
    M = 20;

    print2d();
}    