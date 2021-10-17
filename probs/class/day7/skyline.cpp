#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 2e5;

int N, W, ans, a, b;
stack<int> s;

int main() {
    freopen("skyline.in", "r", stdin);
    freopen("skyline.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> W;

    FOR(i, N) {
        cin >> a >> b;
        while (!s.empty()) {
            if(b < s.top()) {
                s.pop();
            } else {
                break;
            }
        }
        if(s.empty() || b > s.top()) {
            if(!(s.empty() && b == 0)) {
                //cout << a << " " << b << endl;
                ans++;
                s.push(b);
            }
        }
    }

    cout << ans << endl;
}