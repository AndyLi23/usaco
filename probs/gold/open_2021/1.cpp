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

int N, arr[200000], ans;

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> arr[i];
    }

    FOR(i, N-1) {
        unordered_map<int, bool> m;
        m[arr[i]] = true;
        FOR2(j, i + 1, N)
        {
            if(!m[arr[j]]) {
                //cout << i + 1 << " " << j + 1 << endl;
                m[arr[j]] = true;
                ans++;
            } else if (arr[j] == arr[i]) {
                break;
            }
        }
    }

    cout << ans << endl;
}