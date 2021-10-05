#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 500;

int N, a[MAXN][MAXN];

bool seen[MAXN*MAXN];

int get_hash(int i, int j) {
    return i * N + j;
}

int flood(int i, int j, int m) {
    if(!seen[get_hash(i, j)]) {
        seen[get_hash(i, j)] = true;
        int temp = 1;
        if(i > 0 && abs(a[i-1][j] - a[i][j]) <= m) {
            temp += flood(i - 1, j, m);
        }
        if(i < N-1 && abs(a[i+1][j] - a[i][j]) <= m) {
            temp += flood(i + 1, j, m);
        }
        if(j > 0 && abs(a[i][j-1] - a[i][j]) <= m) {
            temp += flood(i, j-1, m);
        }
        if(j < N-1 && abs(a[i][j+1] - a[i][j]) <= m) {
            temp += flood(i, j+1, m);
        }
        return temp;
    }
    return 0;
}

bool check(int m) {
    fill(seen, seen+N*N, false);
    FOR(i, N) {
        FOR(j, N) {
            if(!seen[get_hash(i, j)]) {
                if(flood(i, j, m) >= (N*N+1)/2) return true;
            }
        }
    }

    return false;
}

int main() {
    freopen("tractor2.in", "r", stdin);
    freopen("tractor2.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N;

    int min_, max_;

    FOR(i, N) {
        FOR(j, N) {
            cin >> a[i][j];
            min_ = min(min_, a[i][j]);
            max_ = max(max_, a[i][j]);
        }
    }

    int i = 0, j = max_-min_, m, ans;
    //find minimum value that works (to find maximum, reverse j= and i=)
    while (i <= j) {
        m = (i+j)/2;
        if(check(m)) {
            ans = m;
            j = m - 1;
        } else {
            i = m + 1;
        }
    }

    cout << ans << endl;
}