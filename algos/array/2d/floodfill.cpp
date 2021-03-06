#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)


int N;
int M;

int arr[10000][10000];

//flood fill-----------
int seen[10000][10000];

int DFS(int i, int j) {
    if(i >= 0 && i < N && j >= 0 && j < M && arr[i][j] == 1 && seen[i][j] == 0) {
        seen[i][j] = 1;
        return 1 + DFS(i+1, j) + DFS(i-1, j) + DFS(i, j+1) + DFS(i, j-1);
    }
    return 0;
}

void floodfill() {
    FOR(i, N) {
        FOR(j, M) {
            if(seen[i][j] == 0 && arr[i][j] == 1) {
                cout << DFS(i, j) << "\n";
            }
        }
    }
}
//------------

int main() {

    N = 100;
    M = 100;

    floodfill();
}