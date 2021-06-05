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

int N, cur, base[100005], placed, ans;
vector<int> items[100005];


int main() {
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    ans = N;

    FOR(i, N) {
        cin >> cur;

        if(cur < placed) {
            ans = i;
            break;
        }

        FOR2(j, 1, cur+1) {
            if(!base[j]) {
                base[j] = cur;
            }
        }

        while(!items[base[cur]].empty()) {
            if(items[base[cur]].back() < cur) {
                placed = max(placed, items[base[cur]].back());
                items[base[cur]].pop_back();
            } else {
                break;
            }
        }

        items[base[cur]].push_back(cur);
    }

    cout << ans << endl;
}