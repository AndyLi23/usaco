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

int N, ans, xt, yt, x, y, nx, ny, dx, dy, curx ,cury;
string s;
pair<int, int> temp;
queue<pair<int, int> > q;

bool seen[2005][2005];
int dx1[] = {-1, 0, 1, 0};
int dy1[] = {0, -1, 0, 1};

int main() {
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> s;

    curx = 1002;
    cury = 1002;
    seen[curx][cury] = true;
    FOR(i, N) {
        dx = 0, dy = 0;
        if (s[i] == 'N') {
            dy = 1;
        } else if (s[i] == 'S') {
            dy = -1;
        } else if (s[i] == 'W') {
            dx = -1;
        } else if (s[i] == 'E') {
            dx = 1;
        }
        curx += dx;
        cury += dy;
        seen[curx][cury] = true;
        curx += dx;
        cury += dy;
        seen[curx][cury] = true;
    }

    FOR(i, 2005) {
        FOR(j, 2005) {
            if(!seen[i][j]) {
                ans++;
                
                q.push(make_pair(i, j));

                while(!q.empty()) {
                    temp = q.front();
                    q.pop();
                    x = temp.first;
                    y = temp.second;
                
                    FOR(k, 4) {
                        nx = x + dx1[k];
                        ny = y + dy1[k];
                        if (nx >= 0 && ny >= 0 && nx < 2005 && ny < 2005 && !seen[nx][ny])
                        {
                            seen[nx][ny] = true;
                            q.push(make_pair(nx, ny));
                        }
                    }
                    
                }
            }
        }
    }

    cout << ans-1 << endl;
}