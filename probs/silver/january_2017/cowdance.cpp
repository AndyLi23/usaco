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

int N, T;
int cows[10000];

bool check(int m) {
    priority_queue<int, vector<int>, greater<int> > pq;
    int lowest;

    FOR(i, N) {
        if(pq.size() == m) {
            lowest = pq.top();
            pq.pop();

            pq.push(cows[i] + lowest);
        }
        else {
            pq.push(cows[i]);
        }
    
    }

    while(!pq.empty()) {
        if(pq.top() > T) {
            return false;
        }
        pq.pop();
    }

    return true;
}

int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> T;

    FOR(i, N) {
        cin >> cows[i];
    }

    int i = 1, j = N, m, ans;

    //find minimum value that works (to find maximum, reverse j and i)

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