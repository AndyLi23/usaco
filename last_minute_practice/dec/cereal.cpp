#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N, M, a[100000], b[100000], cows, ans[100000];
unordered_map<int, int> cowtoc;

int main() {
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M;
    FOR(i, N) {
        cin >> a[N - i - 1] >> b[N - i - 1];
    }

    FOR(i, N) {
        int cur = i;
        int val = a[cur];

        while(true) {
            if(cowtoc[val] == 0) {
                cowtoc[val] = cur+1;
                cows++;
                break;
            } else if (cowtoc[val] > cur) {
                break;
            } else {
                int loser = cowtoc[val] - 1;
                cowtoc[val] = cur+1;
                if(val == b[loser]) {
                    break;
                } else {
                    cur = loser;
                    val = b[loser];
                }
            }
        }

        //cout << a[i] << b[i] << cows << endl;

        ans[N - i - 1] = cows;
    }

    FOR(i, N) {
        cout << ans[i] << endl;
    }
}