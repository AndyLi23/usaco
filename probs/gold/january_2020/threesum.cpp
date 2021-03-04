#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, n) for(long long (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(long long (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(long long (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N, Q, A[5000], a, b;
long num[5000][5000];

int m[2000001];

int main() {
    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> Q;
    FOR(i, N) {
        cin >> A[i];
    }

    FOR(i, N) {
        FOR2(j, i + 1, N) {
            if(-A[i] - A[j] >= -1000000 && -A[i] - A[j] <= 1000000) {
                num[i][j] = (long) m[1000000 -A[i] - A[j]];
            }

            m[1000000 + A[j]]++;
        }

        FOR2(j, i + 1, N) {
            m[1000000 + A[j]]--;
        }    
    }

    FOR2R(i, N-1, 0) {
        FOR2(j, i+1, N) {
            num[i][j] += num[i + 1][j] + num[i][j - 1] - num[i + 1][j - 1];
        }
    }

    FOR(i, Q) {
        cin >> a >> b;
        cout << num[a - 1][b - 1] << endl;
    }
}