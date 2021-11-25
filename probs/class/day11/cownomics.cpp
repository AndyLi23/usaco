#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 2e5;

int N, M;
string spotty[500], plain[500];
unsigned long long R[500], hashes1[500], hashes2[500];

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> M;

    FOR(i, N) {
        cin >> spotty[i];
    }
    FOR(i, N) {
        cin >> plain[i];
    }
    FOR(i, M) {
        R[i] = rand() % 1000000000;
    }

    int l = 0;
    int r = 0;
    int best = M;
    int dups = N;

    while(r < M) {
        if(dups == 0) {
            best = min(best, r - l);
        }
        if(dups > 0) {
            map<unsigned long long, bool> counter;
            dups = 0;
            FOR(k, N) {
                hashes1[k] += R[r] * spotty[k][r];
                counter[hashes1[k]] = true;
            }
            FOR(k, N) {
                hashes2[k] += R[r] * plain[k][r];
                if (counter[hashes2[k]])
                    dups++;
            }
            r++;
        } else {
            dups = 0;
            map<unsigned long long, bool> counter;
            FOR(k, N) {
                hashes1[k] -= R[l] * spotty[k][l];
                counter[hashes1[k]] = true;
            }
            FOR(k, N) {
                hashes2[k] -= R[l] * plain[k][l];
                if(counter[hashes2[k]])
                    dups++;
            }
            l++;
        }
    }

    cout << best << endl;
}