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

int C, N, ans, t;
multiset<int> chickens;
vector<pair<int, int> > cows;
pair<int, int> temp;

int main() {
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    //use cin >> and cout <<

    cin >> C >> N;

    FOR(i, C) {
        cin >> t;
        chickens.insert(t);
    }

    FOR(i, N) {
        cin >> temp.second >> temp.first;

        cows.push_back(temp);
    }

    sort(cows.begin(), cows.end());

    FOR(i, N) {
        multiset<int>::iterator it = chickens.lower_bound(cows[i].second);
        if(it != chickens.end() && *it <= cows[i].first) {
            ans++;
            chickens.erase(it);
        }
    }

    cout << ans << endl;
}
