#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
const int MOD = 1000000007;
const int MAXN = 2e5;

int N, cur;

map<int, vector<int> > m;
vector<int> v;

bool cmp(int a, int b) {
    int l=0, r=0;
    FOR(i, 5) {
        if(m[a][i] < m[b][i]) l++;
        else r++;
    }
    return l > r;
}

int main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N;

    FOR(r, 5) {
        FOR(i, N) {
            cin >> cur;
            m[cur].push_back(i);
            if(r==0) v.push_back(cur);
        }
    }

    sort(v.begin(), v.end(), cmp);

    FOR(i, N){
        cout << v[i] << endl;
    }
}