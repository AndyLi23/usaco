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

string s, m, ans;

int main() {
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    //use cin >> and cout <<

    cin >> s >> m;

    int ms = m.size();
    string last = "";

    FOR(i, s.length()) {
        ans += s[i];

        if(last.size() < ms) {
            last += s[i];
        } else {
            last = last.substr(1, last.size());
            last += s[i];
        }

        while(last == m) {
            ans.resize(ans.size() - ms);
            last = ans.substr(max((int)ans.size() - ms, 0), ans.size());
        }
    }

    cout << ans << endl;
}