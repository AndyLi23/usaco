#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N, arr[100000], tem, temp, ans;

map<int, int> m;

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;
    FOR(i, N) {
        cin >> tem >> temp;

        arr[i] = temp;
        m[temp] = tem;
    }

    sort(arr, arr + N);

    int i = 0, j = N - 1;
    while(i <= j) {
        if(i == j) {
            if(m[arr[i]] != 0) {
                ans = max(ans, arr[i] * 2);
            }
            break;
        } else {
            temp = min(m[arr[i]], m[arr[j]]);
            ans = max(ans, arr[i] + arr[j]);

            m[arr[i]] -= temp;
            m[arr[j]] -= temp;

            if(m[arr[i]] == 0) {
                i++;
            }

            if(m[arr[j]] == 0) {
                j--;
            }
        }
    }
    cout << ans;
}