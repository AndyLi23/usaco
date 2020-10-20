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

int N, temp;
vector<int> cows;

int getmin() {
    if((cows[N-2] - cows[0] == N-2 && cows[N-1]-cows[N-2] > 2) || (cows[N-1] - cows[1] == N-2 && cows[1]-cows[0] > 2)) {
        return 2;
    }

    int j=0, best=0;
    FOR(i, N) {
        while (j<N && cows[j]-cows[i]<=N-1) {
            best = max(best, j-i+1);
            j++;
        }
    }
  return N-best;
}

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> temp;
        cows.push_back(temp - 1);
    }

    sort(cows.begin(), cows.end());

    cout << getmin() << endl;

    cout << max(cows[N - 2] - cows[0], cows[N - 1] - cows[1]) - N + 2 << endl;
}