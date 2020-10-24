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

int N, M, ans, cur, tem;
bool good;
string temp;
unordered_map<int, pair<bool, int> > m;

int spots[500][50];
int nospots[500][50];

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M;

    FOR(i, N) {
        cin >> temp;
        FOR(j, M) {
            spots[i][j] = temp[j] - 64;
        }
    }

    FOR(i, N) {
        cin >> temp;
        FOR(j, M) {
            nospots[i][j] = temp[j] - 64;
        }
    }

    FOR(i, M) {
        FOR2(j, i+1, M) {
            FOR2(k, j+1, M) {
                cur++;
                FOR(c, N) {
                    tem = spots[c][i] + spots[c][j] * 26 + spots[c][k] * 26 * 26;
                    m[tem].first = true;
                    m[tem].second = cur;
                }

                good = true;
                FOR(c, N) {
                    tem = nospots[c][i] + nospots[c][j] * 26 + nospots[c][k] * 26 * 26;
                    if(m[tem].first == true && m[tem].second == cur) {
                        good = false;
                        break;
                    }
                }

                if(good) {
                    ans++;
                }
            }
        }
    }

    cout << ans;
}