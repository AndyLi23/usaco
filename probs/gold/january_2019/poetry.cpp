#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N, M, K, words[5005], rhyme[5005], pattern[26], l;


long long MOD = 1000000007;
long long dp[10000], rhymecounter[5005];

long long exp(int base, int power){
   if(power == 0) return 1;
   if(power == 1) return (base + MOD) % MOD;
   long long ans = exp(base,power/2);
   ans = (ans * ans + MOD) % MOD;
   if(power%2 == 1) ans = (ans*base + MOD) % MOD;
   return (ans + MOD) % MOD;
}

int main() {
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M >> K;

    FOR(i, N) {
        cin >> words[i] >> rhyme[i];
    }
    char temp;
    FOR(i, M) {
        cin >> temp;
        l = ((int)temp) - 65;
        pattern[l]++;
    }

    dp[0] = 1;
    FOR(i, K+1) {
        FOR(j, N) {
            if (i + words[j] == K) {
                rhymecounter[rhyme[j]] = (rhymecounter[rhyme[j]] + dp[i] + MOD) % MOD;
            } else {
                dp[i+words[j]] = (dp[i+words[j]] + dp[i] + MOD) % MOD;
            }
        }
    }

    long long ans = 1;

    FOR(j, 26) {
        if(pattern[j] != 0) {
            long long temp = 0;
            FOR(i, N + 1) {
                temp = (MOD + temp + exp(rhymecounter[i], pattern[j])) % MOD;
            }

            ans = (ans * temp + MOD) % MOD;
        }
    }

    cout << ans << endl;
}