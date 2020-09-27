#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
int M;

int arr[10000][10000];

//DFS-----------
int seen[10000][10000];

int DFS(int i, int j) {
    if(i >= 0 && i < N && j >= 0 && j < M && arr[i][j] == 1 && seen[i][j] == 0) {
        seen[i][j] = 1;
        return 1 + DFS(i+1, j) + DFS(i-1, j) + DFS(i, j+1) + DFS(i, j-1);
    }
    return 0;
}
//------------

int main() {

    N = 100;
    M = 100;

    //DFS----------
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(seen[i][j] == 0 && arr[i][j] == 1) {
                cout << DFS(i, j) << "\n";
            }
        }
    }
    //-----------
}