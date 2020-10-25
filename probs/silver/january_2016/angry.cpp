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

int N, K, temp, minbale, maxbale;

set<int> bales;
set<int>::iterator it;

bool check(int m) {
    int cur = minbale;
    temp = K;
    while(temp > 0) {
        temp--;
        it = bales.lower_bound(cur + 2 * m + 1);
        if(it == bales.end()) {
            return true;
        }
        cur = *it;
    }

    return cur > maxbale;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> K;

    FOR(i, N) {
        cin >> temp;
        bales.insert(temp);
    }

    minbale = *bales.begin();
    maxbale = *bales.rbegin();

    int i = 0, j = 1000000005, m, ans;

    while (i <= j) {
        m = (i+j)/2;

        if(check(m)) {
            ans = m;
            j = m - 1;
        } else {
            i = m + 1;
        }
    }

    cout << ans << endl;
}