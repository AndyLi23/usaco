#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

#define FOR(i, n) for(long long (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(long long (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(long long (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

long long N;
long long x[2500], y[2500], arr[2500];
long long total;

long long p2(long long n) {
    long long temp = 1;
    FOR(i, n) {
        temp = temp * 2;
    }
    return temp;
}

bool comp(int i, int j) {
    return x[i] < x[j];
}

int main() {
    //comment out for submission
    //freopen("2.in", "r", stdin);
    //freopen("2.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> x[i] >> y[i];
        arr[i] = i;
    }

    sort(arr, arr + N, comp);

    FOR(i, N) {
        vector<long long> above;
        vector<long long> below;
        long long ta = 0, tb = 0, ma = 1000000005, mb = -1000000005;

        total += 1;

        FOR2(j, i + 1, N) {
            total += 1;
            if (y[arr[j]] < y[arr[i]]){
                FOR(k, below.size()) {
                    if(below[k] < y[arr[j]]) {
                        total += 1;
                    }
                }
                below.push_back(y[arr[j]]);

                if(y[arr[j]] > mb) {
                    tb++;
                }
                mb = max(mb, y[arr[j]]);
            }
            else
            {
                FOR(k, above.size()) {
                    if(above[k] > y[arr[j]]) {
                        total += 1;
                    }
                }
                above.push_back(y[arr[j]]);

                if(y[arr[j]] < ma) {
                    ta++;
                }
                ma = min(ma, y[arr[j]]);
            }

            total += ta * tb;
        }
    }

    cout << total + 1 << endl;
}