#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
#define MAXN = 2e5;

int N, xL, yL, xB, yB, xtemp, ytemp;
map<int, vector<int> > vertical_to_horizontal, horizontal_to_vertical;
map<int, bool> seenX, seenY;

struct Line {
    bool hor;
    int x, y, counter;
};

queue<Line> q;

int main() {
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> xL >> yL >> xB >> yB;


    FOR(i, N) {
        cin >> xtemp >> ytemp;
        vertical_to_horizontal[xtemp].pb(ytemp);
        horizontal_to_vertical[ytemp].pb(xtemp);
    }

    q.push({true, 0, yL, 0});
    q.push({false, xL, 0, 0});

    while(!q.empty()) {
        Line cur = q.front();
        q.pop();

        //cout << cur.hor << " " << cur.x << " " << cur.y << endl;
        if((cur.hor && cur.y == yB) || (!cur.hor && cur.x == xB)) {
            cout << cur.counter << endl;
            return 0;
        }
        if(cur.hor) {
            for(auto i : horizontal_to_vertical[cur.y]) {
                if(!seenX[i]) {
                    seenX[i] = true;
                    q.push({false, i, 0, cur.counter + 1});
                }
            }
        } else {
            for(auto i : vertical_to_horizontal[cur.x]) {
                if(!seenY[i]) {
                    seenY[i] = true;
                    q.push({true, 0, i, cur.counter + 1});
                }
            }
        }
    }
    cout << -1 << endl;
}