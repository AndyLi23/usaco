#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 100005;

int N, first[MAXN], last[MAXN], temp, A[MAXN], ans;

int main() {
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N;
    FOR(i, N) {
        cin >> temp;
        if(temp != 0) {
            if(!first[temp]) first[temp] = i + 1;
            last[temp] = i + 1;
        }
        A[i] = temp;
    }

    stack<int> s;

    FOR(i, N) {
        temp = A[i];
        if(i == first[temp]-1) {
            s.push(temp);
            ans = max(ans, (int) s.size());
            if(i == last[temp]-1) {
                s.pop();
            }
        } else if (i == last[temp]-1) {
            if(s.top() != temp) {
                ans = -1;
                break;
            }
            s.pop();
        }
    }

    cout << ans << endl;
}