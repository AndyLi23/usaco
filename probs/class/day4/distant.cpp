#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
#define MAXN = 2e5;

int N, A, B;
char grid[50][50];
ll dist[2000][2000], ans;
string temp;


void fw() {
    FOR(i, N*N) {
        FOR(j, N*N) {
            if (i==j) dist[i][j]=0;
            else if (dist[i][j] == -1) dist[i][j] = LLONG_MAX;
        }
    }
    FOR(k, N*N) {
        FOR(i, N*N) {
            FOR(j, N*N) {
                if(dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int hash_(int i, int j) {
    return i * N + j;
}

int get(int i, int j, int i1, int j1) {
    if(grid[i][j] == grid[i1][j1]) return A;
    else return B;
}

int main() {
    freopen("distant.in", "r", stdin);
    freopen("distant.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> A >> B;
    FOR(i, N) {
        cin >> temp;
        FOR(j, N) {
            grid[i][j] = temp[j];
        }
    }

    FOR(i, N*N) {
        FOR(j, N*N) {
            dist[i][j] = -1;
        }
    }

    FOR(i, N) {
        FOR(j, N) {
            if(i > 0) dist[hash_(i, j)][hash_(i - 1, j)] = get(i, j, i - 1, j);
            if(i < N-1) dist[hash_(i, j)][hash_(i + 1, j)] = get(i, j, i + 1, j);
            if(j > 0) dist[hash_(i, j)][hash_(i, j-1)] = get(i, j, i, j-1);
            if(j < N-1) dist[hash_(i, j)][hash_(i, j+1)] = get(i, j, i, j+1);
        }
    }

    fw();

    FOR(i, N*N) {
        FOR(j, N*N) {
            //cout << dist[i][j] << " ";
            ans = max(ans, dist[i][j]);
        }
        //cout << endl;
    }

    cout << ans << endl;
}