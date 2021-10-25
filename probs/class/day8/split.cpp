#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 2e5;

int N;
pair<int, int> cows[50000], cowsy[50000];
multiset<int> leftx, lefty, rightx, righty, upx, upy, downx, downy;
ll maxarea, minarea = LLONG_MAX, minareay = LLONG_MAX;

int main() {
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N;
    FOR(i, N) {
        cin >> cows[i].first >> cows[i].second;
        rightx.insert(cows[i].first);
        righty.insert(cows[i].second);

        cowsy[i] = {cows[i].second, cows[i].first};
        downx.insert(cows[i].first);
        downy.insert(cows[i].second);

    }

    sort(cows, cows + N);
    sort(cowsy, cowsy + N);

    maxarea = ((ll)(*rightx.rbegin() - *rightx.begin())) * ((ll)(*righty.rbegin() - *righty.begin()));

    FOR(i, N) {
        leftx.insert(cows[i].first);
        lefty.insert(cows[i].second);

        rightx.erase(rightx.find(cows[i].first));
        righty.erase(righty.find(cows[i].second));

        if(rightx.size() > 0) {
            minarea = min(minarea, ((ll)(*rightx.rbegin() - *rightx.begin())) * ((ll)(*righty.rbegin() - *righty.begin())) +
                                ((ll)(*leftx.rbegin() - *leftx.begin())) * ((ll)(*lefty.rbegin() - *lefty.begin())));
        } else {
            minarea = min(minarea, ((ll)(*leftx.rbegin() - *leftx.begin())) * ((ll)(*lefty.rbegin() - *lefty.begin())));
        }
    }

    FOR(i, N) {
        upy.insert(cowsy[i].first);
        upx.insert(cowsy[i].second);

        downy.erase(downy.find(cowsy[i].first));
        downx.erase(downx.find(cowsy[i].second));

        if(downx.size() > 0) {
            minareay = min(minareay, ((ll)(*downx.rbegin() - *downx.begin())) * ((ll)(*downy.rbegin() - *downy.begin())) +
                                ((ll)(*upx.rbegin() - *upx.begin())) * ((ll)(*upy.rbegin() - *upy.begin())));
        } else {
            minareay = min(minareay, ((ll)(*upx.rbegin() - *upx.begin())) * ((ll)(*upy.rbegin() - *upy.begin())));
        }
    }

    cout << maxarea - min(minarea, minareay) << endl;
}