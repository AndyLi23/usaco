#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N, cur, l[100005], first[100005], last[100005], ans;

int main() {
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> cur;
        if(cur != 0) {
            if(!first[cur]) {
                first[cur] = i;
                last[cur] = i;
            } else {
                last[cur] = i;
            }
        }
        l[i] = cur;
    }

    stack<int> s;

    FOR(i, N) {
        cur = l[i];
        if(first[cur] == i) {
            s.push(cur);
            ans = max(ans, (int) s.size());
            if(last[cur] == i) {
                s.pop();
            }
        }
        else if (last[cur] == i)
        {
            if(s.top() != cur) {
                cout << -1 << endl;
                return -1;
            }
            s.pop();
        }

    }

    cout << ans << endl;
}