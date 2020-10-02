#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[10000][10000];

int N, M;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)


//print array -----------------
void print2d() {
    FOR(i, N) {
        FOR(j, M) {
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