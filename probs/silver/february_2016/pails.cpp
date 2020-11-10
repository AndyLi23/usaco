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

int X, Y, K, M, x, y;
bool can[101][101];
bool new_[101][101];

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    //use cin >> and cout <<

    cin >> X >> Y >> K >> M;

    can[0][0] = true;

    FOR(i, K) {
        FOR(i, 101) {
            fill(new_[i], new_[i] + 101, false);
        }

        FOR(x, X+1) {
            FOR(y, Y+1) {
                if(can[x][y]) {
                    new_[x][y] = true;
                    new_[x][Y] = true;
                    new_[X][y] = true;
                    new_[0][y] = true;
                    new_[x][0] = true;

                    if(y-(X-x) >= 0) {
                        new_[X][y - (X-x)] = true;
                    }
                    if(x-(Y-y) >= 0) {
                        new_[x - (Y-y)][Y] = true;
                    }
                    if(x+y <= X) {
                        new_[x + y][0] = true;
                    }
                    if(x+y <= Y) {
                        new_[0][x + y] = true;
                    }
                }
            }
        }
        
        FOR(i, X+1) {
            FOR(j, Y+1) {
                can[i][j] = new_[i][j];
            }
        }
        
    }

    int ans = 1000000000;
    FOR(i, X + 1) {
        FOR(j, Y+1) {
            if(can[i][j]) {
                ans = min(ans, abs(M-i-j));
            }
        }
    }
    cout << ans << endl;
}