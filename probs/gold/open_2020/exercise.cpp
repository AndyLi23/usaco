#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
const int MAXN = 1e4+1;

int N, MOD;
vector<int> primes;
bool composite[MAXN];
ll dp[2000][MAXN];

ll mul(ll x, ll y) {
    return (x * y) % MOD;
}
 
ll add(ll x, ll y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}
 
ll sub(ll x, ll y) {
    x -= y;
    if (x < 0) x += MOD;
    return x;
}

int main() {
    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> MOD;

    for (int i = 2; i <= N; i++) {
        if(!composite[i]) {
            primes.pb(i);
            for (int j = i * i; j <= N; j += i) {
                composite[j] = true;
            }
        }
    }


    FOR(i, N+1) dp[0][i] = 1;

    for (int i = 1; i <= primes.size(); i++) {
        FOR(j, N+1) {
            dp[i][j] = dp[i - 1][j]; // carry over sum of K without using this prime

            int p = primes[i-1];

            while(p <= j) { //from definition: this stores the sum of K when n = j
                dp[i][j] = add(dp[i][j], mul(p, dp[i - 1][j - p])); //add p to the sum of K, dp[i - 1][j - p] times because K is product of relatively prime factors.
                                                                    //for example, say dp[i-1][j-p] = 3 (1 + 2). Then the new possibilities for K are p * 1 and p * 2.
                                                                    //Adding these is the same as adding p * 3 or p * dp[i-1][j-p]. We do not care if this is bounded by
                                                                    //j because K is not bounded: by definition, p + j-p = j so the total number of spaces used is only j.
                p *= primes[i-1];
            }
        }
    }

    FOR(i, primes.size()+1) {
        FOR(j, N+1) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[primes.size()][N] << endl;
}