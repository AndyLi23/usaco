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

int N, maxnum, temp, temp1;
map<int, int> m;

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;
    FOR(i, N-1) {
        cin >> temp >> temp1;
        m[temp]++;
        m[temp1]++;
        maxnum = max(max(maxnum, m[temp1]), max(maxnum, m[temp]));
    }

    cout << maxnum + 1 << endl;
}