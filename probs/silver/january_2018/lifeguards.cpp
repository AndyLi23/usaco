#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

class Point {
    public:
        int time, lifeguard, on;
};

class myComparator { 
    public: 
    int operator() (const Point& e1, const Point& e2) { 
        return e1.time < e2.time; 
    } 
}; 

int N, totalTime, alone[100005], pv, ans;
Point points[200005], temp;
set<int> active;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        temp = Point();
        cin >> temp.time;
        temp.lifeguard = i;
        temp.on = 1;
        points[2 * i] = temp;

        temp = Point();
        cin >> temp.time;
        temp.lifeguard = i;
        temp.on = 0;
        points[2 * i+1] = temp;
    }

    sort(points, points + 2*N, myComparator());



    FOR(i, 2*N) {
        if(active.size() == 1) {
            alone[*active.begin()] += points[i].time - pv;
        }
        if(!active.empty()) {
            totalTime += points[i].time - pv;
        }

        if(points[i].on == 0) {
            active.erase(active.find(points[i].lifeguard));
        } else {
            active.insert(points[i].lifeguard);
        }

        pv = points[i].time;
    }

    FOR(i, N) {
        ans = max(ans, totalTime - alone[i]);
    }

    cout << ans << endl;
}