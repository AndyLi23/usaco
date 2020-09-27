#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[10000][10000];

int main() {
    int N = 20;
    int M = 20;

    //print array -----------------
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    //----------------------------
}    