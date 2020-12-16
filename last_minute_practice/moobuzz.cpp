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

int N;

int main() {
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    int first8[8] = {1, 2, 4, 7, 8, 11, 13, 14};

    cout << (first8[((N-1) % 8)] + (15 * ((N-1)/8))) << endl;
}