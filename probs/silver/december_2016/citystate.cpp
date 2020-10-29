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

int N, ans, tn, tn1;
string temp, temp1;

map<string, int> m1;

int main() {
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> temp;
        cin >> temp1;

        m1[temp.substr(0, 2) + temp1]++;
    }

    map<string, int>::iterator it;
    for (it = m1.begin(); it != m1.end(); it++) {
        if(it->first.substr(2, 4) != it->first.substr(0, 2)) {
            ans += it->second * (m1[it->first.substr(2, 4) + it->first.substr(0, 2)]);
        }
    }

    cout << ans / 2 << endl;
}