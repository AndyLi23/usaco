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

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first != p2.first) {
        return p1.first < p2.first;
    } else {
        return p1.second > p2.second;
    }
}

int N, ans;
vector<pair<int, int> > mtns;
int temp, temp1;

int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> temp >> temp1;
        mtns.push_back(make_pair(temp-temp1, temp+temp1));
    }

    sort(mtns.begin(), mtns.end(), cmp);

    int prev = -2000000000;
    FOR(i, N) {
        if(mtns[i].second > prev) {
            ans++;
        }
        prev = max(prev, mtns[i].second);
    }

    cout << ans << endl;
}