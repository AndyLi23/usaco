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

int N;
bool grid[1000][1000];
string temp;

int main() {
    freopen("leftout.in", "r", stdin);
    freopen("leftout.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> temp;
        FOR(j, N) {
            grid[i][j] = temp[j] == 'R';
        }
    }

    FOR(i, N) {
        if(!grid[0][i]) {
            FOR(j, N) {
                grid[j][i] = !grid[j][i];
            }
        }
    }

    FOR(i, N) {
        if(!grid[i][0]) {
            FOR(j, N) {
                grid[i][j] = !grid[i][j];
            }
        }
    }

    int count = 0;
    FOR2(i, 1, N) {
        FOR2(j, 1, N) {
            if(!grid[i][j]) {
                count++;
            }
        }
    }
    if(count == (N-1)*(N-1)) {
        cout << "1 1";
        return 0;
    } else if (count == 0) {
        cout << "-1";
        return 0;
    }

    FOR2(i, 1, N) {
        count = 0;
        FOR2(j, 1, N) {
            if(!grid[j][i]) {
                count++;
            }
        }
        if(count == N-1) {
            cout << "1 " << i + 1;
            return 0;
        }
    }

    FOR2(i, 1, N) {
        count = 0;
        FOR2(j, 1, N) {
            if(!grid[i][j]) {
                count++;
            }
        }
        if(count == N-1) {
            cout << i+1 << " 1";
            return 0;
        } else if (count != 0) {
            FOR2(j, 1, N) {
                if(!grid[i][j]) {
                    cout << i + 1 << " " << j + 1;
                    return 0;
                }
            }
        }
    }
}