#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N, t1, t2, ans;

pair<int, int> x[50000], y[50000];

int getperim(int i, int i1, int j, int j1) {
    return (x[i1].first - x[i].first) * (y[j1].first - y[j].first);
}

int getoutside(int i, int i1, int j, int j1) {
    set<int> outside;
    FOR(i2, 4)
    {
        if(x[i2].first < x[i].first) {
            outside.insert(x[i2].second);
        }
    }
    FOR2R(i3, N-1, N-4) {
        if(x[i3].first > x[i1].first) {
            outside.insert(x[i3].second);
        }
    }
    FOR(j2, 4) {
        if(y[j2].first < y[j].first) {
            outside.insert(y[j2].second);
        }
    }
    FOR2R(j3, N-1, N-4) {
        if(y[j3].first > y[j1].first) {
            outside.insert(y[j3].second);
        }
    }

    return outside.size();
}

int main() {
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> t1 >> t2;
        x[i] = make_pair(t1, i);
        y[i] = make_pair(t2, i);
    }

    sort(x, x + N);
    sort(y, y + N);

    // cout << getperim(0, 4, 0, 4) << endl;

    ans = 2000000000;

    FOR(i, 4) {
        FOR2R(i1, N-1, N-4) {
            FOR(j, 4) {
                FOR2R(j1, N-1, N-4) {

                    if(i <= i1 && j <= j1 && getoutside(i, i1, j, j1) <= 3) {
                        //cout << i << i1 << j << j1<< " " << getperim(i, i1, j, j1) << endl;
                        ans = min(ans, getperim(i, i1, j, j1));
                    }

                }

            }

        }

    }

    cout << ans << endl;
}