#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
const int MOD = 1000000007;
const int MAXN = 2e5;

int N, k;
char c;

int val[80005], pre[80005];

int main() {
    freopen("ttravel.in", "r", stdin);
    freopen("ttravel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N;

    val[0] = -1;
    pre[0] = 0;

    FOR2(i, 1, N+1) {
        cin >> c;

        if(c == 'a') {
            cin >> k;
            val[i] = k;
            pre[i] = i-1;
        } else if (c == 's') {
            val[i] = val[pre[i-1]];
            pre[i] = pre[pre[i-1]];
        } else {
            cin >> k;
            val[i] = val[k - 1];
            pre[i] = pre[k - 1];
        }

        cout << val[i] << endl;
    }
}