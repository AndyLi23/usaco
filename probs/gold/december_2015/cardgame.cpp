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

int N, c, e[100005], ans;
vector<int> e1, e2, b;

set<int> b1, b2;

int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N/2) {
        cin >> c;
        e1.push_back(c);
        e[c] = 1;
    }
    FOR(i, N/2) {
        cin >> c;
        e2.push_back(c);
        e[c] = 1;
    }
    FOR2(i, 1, 2*N+1) {
        if(!e[i]) {
            b.push_back(i);
        }
    }
    sort(b.rbegin(), b.rend());
    FOR(i, N) {
        if(i < N/2) {
            b1.insert(b[i]);
        } else {
            b2.insert(b[i]);
        }
    }

    //SETUP DONE

    

    //first N/2

    FOR(i, N/2) {
        if(e1[i] < *b1.rbegin()) {
            ans++;
            b1.erase(b1.lower_bound(e1[i]));
        } else {
            b1.erase(b1.begin());
        }
    }



    FOR(i, N/2) {

        if(e2[i] > *b2.begin()) {
            ans++;
            set<int>::iterator it = b2.lower_bound(e2[i]);
            it--;
            b2.erase(it);
        } else {
            b2.erase(prev(b2.end()));
        }
    }

    cout << ans << endl;
}