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

int N, Q, temp, q1, q2;
int ha[100005];
int ga[100005];
int ja[100005];

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> Q;

    FOR(i, N) {
        cin >> temp;

        if(temp == 1) {
            ha[i] = 1;
        } else if (temp == 2) {
            ga[i] = 1;
        } else {
            ja[i] = 1;
        }

        if(i > 0) {
            ha[i] += ha[i - 1];
            ga[i] += ga[i - 1];
            ja[i] += ja[i - 1];
        }
    }

    FOR(i, Q) {
        cin >> q1 >> q2;

        cout << ha[q2-1] - ha[q1-2] << " " << ga[q2-1] - ga[q1-2]  << " " << ja[q2-1] - ja[q1-2]  << endl;
    }
}