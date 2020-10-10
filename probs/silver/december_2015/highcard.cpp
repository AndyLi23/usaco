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

int N, temp, ans;

vector<int> elsie;
vector<int> bessie;
int seen[100005];

int main() {
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> temp;
        elsie.push_back(temp);
        seen[temp] = 1;
    }

    sort(elsie.begin(), elsie.begin() + N);

    FOR2(i, 1, 2*N+1) {
        if(seen[i] == 0) {
            bessie.push_back(i);
        }
    }

    sort(bessie.begin(), bessie.begin() + N, greater<int>());

    int curJ = N - 1;
    FOR(i, N) {
        while(curJ >= 0 && bessie[i] < elsie[curJ]) {
            curJ--;
        }

        //cout << bessie[i] << " " << elsie[curJ] << endl;

        ans++;
        curJ--;

        if(curJ < 0)
            break;
    }

    cout << ans << endl;
}