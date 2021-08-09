#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
const int MOD = 1000000007;

int N;
unsigned long long fac[1000001];

unsigned long long power(unsigned long long x, int y, int p) {
    unsigned long long res = 1; // Initialize result
    x = x % p; // Update x if it is more than or equal to p
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) res = (res * x) % p;
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, int p) {
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little theorem.
unsigned long long nCrModPFermat(unsigned long long n, int r, int p) {
    // If n<r, then nCr should return 0
    if (n < r) return 0;
    // Base case
    if (r == 0) return 1;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

int main() {
    fac[0] = 1;
    for (int i = 1; i <= 1000000; i++) fac[i] = (fac[i - 1] * i) % MOD;
}