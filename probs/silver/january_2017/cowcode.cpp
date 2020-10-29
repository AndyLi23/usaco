#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

string code;
long long  N;

int main() {
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);
    //use cin >> and cout <<

    cin >> code >> N;

    long long size = code.size(), origsize = code.size();

    while(size < N) {
        size *= 2;
    }

    while(N > origsize) {
        if(N > size/2) {
            if(N == size/2 + 1) {
                N -= 1;
            } else {
                N -= (size / 2 + 1);
            }
        }
        size /= 2;
    }

    cout << code[N-1] << endl;
}