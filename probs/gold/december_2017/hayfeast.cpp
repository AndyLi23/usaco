#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

long long N, M, h[100000], s[100000], l, r, cur, prv, rm[100000], ans;
multiset<long long> ms;

int main() {
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M;

    FOR(i, N) {
        cin >> h[i] >> s[i];
    }

    l = 0;
    r = 0;
    cur = h[0];

    while(r < N) {
        if(cur >= M) {
            rm[l] = r;
            cur -= h[l];
            l++;
        } else {
            r++;
            if(r < N) {
                cur += h[r];
            }
        }
    }

    prv = -1;

    ans = 2000000000;

    FOR(i, N) {
        if(i!=0 && rm[i]==0) {
            break;
        }
        if(i>0) {
            ms.erase(ms.find(s[i - 1]));
        }

        while(prv < rm[i]) {
            prv++;
            ms.insert(s[prv]);
        }
            

        ans = min(ans, *ms.rbegin());
    }

    cout << ans << endl;
}