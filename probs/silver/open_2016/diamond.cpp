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

int N, K, max1, max1i, max2, max2i;
int d[50000];

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> K;

    FOR(i, N) {
        cin >> d[i];
    }

    sort(d, d + N);

    FOR(i, N) {
        int j = i;
        while(d[j] - d[i] <= K && j < N) {
            j++;
        }
        if (j - i >= max1) {
            max1 = j - i;
            max1i = i;
        }
    }

    FOR2(i, max1i, max1i+max1) {
        d[i] = -1;
    }

    FOR(i, N) {
        if(d[i] != -1) {
            int j = i;
            while(d[j] - d[i] <= K && j < N && d[j] != -1) {
                j++;
            }
            if (j - i >= max2) {
                max2 = j - i;
                max2i = i;
            }
        }
    }

    cout << max1 + max2 << endl;
}