#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 2e5;

int N, dist[210];
pair<int, int> A[210];

map<vector<int>, int> m;

int main() {
    freopen("lightsout.in", "r", stdin);
    freopen("lightsout.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N;

    FOR(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    A[N] = {0, 0};

    vector<int> S(1, 0);

    FOR(i, N) {
        int j = (i + 1) % N;
        int k = (i + 2) % N;

        S.pb(abs(A[i].first - A[j].first) + abs(A[i].second - A[j].second));

        if ((A[i].first - A[j].first) * (A[k].second - A[j].second) > (A[k].first - A[j].first) * (A[i].second - A[j].second)) {
            S.pb(-1);
        } else {
            S.pb(-2);
        }
    }

    S[S.size() - 1] = 0;

    FOR2(i, 0, N-1) {
        dist[i+1] = dist[i] + S[2*i+1];
    }
    dist[N] = 0;
    FOR2R(i, N-1, 0) {
        dist[i] = min(dist[i], dist[i+1] + S[2*i+1]);
    }


    for (int i = 0; i < S.size(); i+=2) {
        for (int j = 1; j + i <= S.size(); j+= 2) {
            m[vector<int>(S.begin() + i, S.begin() + i + j)]++;
        }
    }

    int ans = 0;

    for (int i = 2; i + 2 < S.size(); i += 2) {
        int j;
        int cost = 0;
        for (j = 1;; j += 2) {
            if(m[vector<int>(S.begin() + i, S.begin() + i + j)] == 1) {
                break;
            }
            cost += S[i + j];
        }

        ans = max(ans, cost + dist[(i + j) / 2] - dist[i / 2]);
    }

    cout << ans << endl;
}