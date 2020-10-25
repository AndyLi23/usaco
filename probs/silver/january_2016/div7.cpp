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

int N, ans, sum_;
int arr[50000], lower[50000], upper[50000];

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> arr[i];
        sum_ = sum_ + arr[i] % 7;
    }

    lower[0] = arr[0]%7;
    upper[N - 1] = arr[N - 1]%7;
    FOR2(i, 1, N)
    {
        lower[i] = (lower[i - 1] + arr[i]) % 7;
        upper[N - i - 1] = (upper[N-i] + arr[N-i-1]) % 7;
    }

    FOR(i, N/3) {
        FOR2R(j, N-1, max(2*N/3, i+1)) {
            if((sum_ - lower[i] - upper[j]) % 7 == 0) {
                ans = max(ans, j - i-1);
                break;
            }
        }
    }

    cout << ans << endl;
}