#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N, Q, fence[100000], prefix[100000], start, a, b;
string s;
set<int> sb, sr;
vector<int> sbv, srv;

int main() {
    //freopen("2.in", "r", stdin);
    //freopen("2.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> Q >> s;

    FOR(i, N) {
        fence[i] = s[i]-65;
    }

    FOR(i, 26) {

        start = -1;

        FOR(j, N) {
            if(fence[j] == i) {
                if(start == -1) {
                    start = j;
                }
            } else if (fence[j] < i) {
                if(start != -1) {
                    sb.insert(start);
                    start = -1;
                }
            }
        }

        if(start != -1) {
            sb.insert(start);
        }

        start = -1;

        FOR2R(j, N-1, 0) {
            if(fence[j] == i) {
                if(start == -1) {
                    start = j;
                }
            } else if (fence[j] < i) {
                if(start != -1) {
                    sr.insert(start);
                    start = -1;
                }
            }
        }

        if(start != -1) {
            sr.insert(start);
        }

    }

    for(set<int>::iterator it = sb.begin(); it != sb.end(); it++) {
        sbv.push_back(*it);
    }
    for(set<int>::iterator it = sr.begin(); it != sr.end(); it++) {
        srv.push_back(*it);
    }

    FOR(i, Q) {
        cin >> a >> b;
        int ans = 0;
        if(a != 1) { 
            ans += distance(sbv.begin(), upper_bound(sbv.begin(), sbv.end(), a-2));
        }
        if(b != N) {
            ans += distance(lower_bound(srv.begin(), srv.end(), b), srv.end());
        }
        cout << ans << endl;
    }
}