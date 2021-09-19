#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
#define MAXN = 2e5;

int N, M, K;
char tmp;
int nxt[1000][2];
int directions[500];
int graph[1000];
int pv[1000];

int main() {
    freopen("cruise.in", "r", stdin);
    freopen("cruise.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N >> M >> K;

    FOR(i, N) {
        cin >> nxt[i][0] >> nxt[i][1];
        nxt[i][0]--;
        nxt[i][1]--;
    }

    FOR(i, M) {
        cin >> tmp;
        directions[i] = (tmp == 'R');
    }

    FOR(i, N) {
        int end = i;
        FOR(j, M) {
            end = nxt[end][directions[j]];
        }
        graph[i] = end;
    }

    int cycle = 1;
    int before = 0;

    fill(pv, pv + N, -1);

    int cur = 0, prev = 0;
    while(pv[cur] == -1) {
        prev = cur;
        cur = graph[cur];
        pv[prev] = cur;
        before++;
    }

    int end = prev;
    int cur2 = cur;
    while (cur != end) {
        cur = pv[cur];
        cycle++;
    }

    before = before - cycle;
    int other = (K - before) % cycle;

    FOR(i, other) {
        cur2 = graph[cur2];
    }

    cout << cur2+1 << endl;
}