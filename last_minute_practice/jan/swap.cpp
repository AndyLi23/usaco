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

int N, M, K, a[100000], l, r, temp, curcycle, cyclenum[100000], cyclenum2[100000], j, cyclecount;
vector<int> cycles[100000];

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M >> K;

    FOR(i, N) {
        a[i] = i;
    }

    FOR(i, M) {
        cin >> l >> r;
        l--;
        r--;
        FOR(j, (r-l+1)/2) {
            temp = a[l + j];
            a[l+j] = a[r-j];
            a[r-j] = temp;
        }
    }


    curcycle++;
    FOR(i, N) {
        if(!cyclenum[i]) {
            cyclecount = 0;
            cyclenum[i] = curcycle;
            cyclenum2[i] = cyclecount;
            cycles[curcycle].push_back(i);

            j = a[i];
            while(j != i) {
                cyclecount++;
                cyclenum2[j] = cyclecount;
                cyclenum[j] = curcycle;
                cycles[curcycle].push_back(j);
                j = a[j];
            }

            curcycle++;
        }
    }

    FOR(i, N) {
        cout << cycles[cyclenum[i]][(K+cyclenum2[i])%cycles[cyclenum[i]].size()]+1 << endl;
    }
}