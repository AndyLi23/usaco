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
    int a[5] = {1, 2, 3, 6, 8};
    int sum_ = 0;
    FOR2(i, 1, 5) {
        sum_ += a[i] - a[0];
    }

    FOR2(i, 1, 5) {
        sum_ += (2 * (i - 1) - N) * (a[i] - a[i - 1]);
    }
}