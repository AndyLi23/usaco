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

class Rect {
    public:
    int x1, y1, x2, y2;
};

int N, cur, ans;
string temp;

vector<Rect> pcls;
Rect tem;

int arr[20][20];
int seen[20][20];

int DFS(int i, int j, int u11, int u22, int u1, int u2, int target) {
    if(i >= u11 && i < u1 && j >= u22 && j < u2 && arr[i][j] == target && seen[i][j] < cur) {
        seen[i][j] = cur;
        return 1 + DFS(i+1, j, u11, u22, u1, u2, target) + DFS(i-1, j, u11, u22, u1, u2, target) + DFS(i, j+1, u11, u22, u1, u2, target) + DFS(i, j-1, u11, u22, u1, u2, target);
    }
    return 0;
}


bool isPCL(Rect r) {
    cur++;

    int colors[26], cur1 = -1, cur2 = -1;
    FOR(i, 26) {
        colors[i] = 0;
    }

    FOR2(i, r.x1, r.x2+1) {
        FOR2(j, r.y1, r.y2+1) {
            if(seen[i][j] < cur) {
                colors[arr[i][j]]++;
                DFS(i, j, r.x1, r.y1, r.x2 + 1, r.y2 + 1, arr[i][j]);
            }
        }
    }

    FOR(i, 26) {
        if(colors[i] > 0) {
            if(colors[i] == 1 && cur1 == -1) {
                cur1 = 1;
            } else if (colors[i] > 1 && cur2 == -1) {
                cur2 = 1;
            } else {
                return false;
            }
        }
    }

    return cur1 != -1 && cur2 != -1;
}

bool contains(Rect r1, Rect r2) {
    return r1.x1 >= r2.x1 && r1.x2 <= r2.x2 && r1.y1 >= r2.y1 && r1.y2 <= r2.y2;
}

bool ismaximal(int k) {
    FOR(i, pcls.size()) {
        if(k != i) {
            if(contains(pcls[k], pcls[i])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> temp;
        FOR(j, N) {
            arr[i][j] = temp[j] - 65;
        }
    }


    FOR(i1, N) {
        FOR(j1, N) {
            FOR2(i2, i1, N) {
                FOR2(j2, j1, N) {
                    tem.x1 = i1, tem.x2 = i2, tem.y1 = j1, tem.y2 = j2;
                    if(isPCL(tem)) {
                        pcls.push_back(tem);
                    }
                }
            }
        }
    }

    FOR(i, pcls.size()) {
        if(ismaximal(i)) {
            ans++;
        }
    }

    cout << ans << endl;

}