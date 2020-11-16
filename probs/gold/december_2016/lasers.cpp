#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N, xl, yl, xb, yb, ans, tx, ty;
unordered_map<int, vector<int> > xtoy;
unordered_map<int, vector<int> > ytox;
unordered_map<int, bool> seenx;
unordered_map<int, bool> seeny;

class Line {
    public:
        bool hor;
        int x, y, pl;
};

Line te;

Line make_line(bool hor, int x, int y, int pl) {
    te.hor = hor;
    te.x = x;
    te.y = y;
    te.pl = pl;
    return te;
}

int main() {
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> xl >> yl >> xb >> yb;
    ans = -1;

    FOR(i, N) {
        cin >> tx >> ty;
        xtoy[tx].push_back(ty);
        ytox[ty].push_back(tx);
    }

    queue<Line> q;
    q.push(make_line(false, xl, 0, 0));
    q.push(make_line(true, 0, yl, 0));
    while(!q.empty()) {
        Line temp = q.front();
        q.pop();
        if ((temp.hor && temp.y == yb) || (!temp.hor && temp.x == xb)) {
            ans = temp.pl;
            break;
        }
        if(temp.hor) {
            FOR(i, ytox[temp.y].size()) {
                tx = ytox[temp.y][i];
                if(!seenx[tx]) {
                    seenx[tx] = true;
                    q.push(make_line(false, tx, 0, temp.pl + 1));
                }
            }
        } else {
            FOR(i, xtoy[temp.x].size()) {
                ty = xtoy[temp.x][i];
                if(!seeny[ty]) {
                    seeny[ty] = true;
                    q.push(make_line(true, 0, ty, temp.pl + 1));
                }
            }
        }
    }

    cout << ans << endl;
}