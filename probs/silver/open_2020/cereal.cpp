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

int N, M, cntr, j, k, cur;
int cereal_to_cow[100001];
int ans[100001];

int main() {
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M;

    vector<pair<int, int> > cows = vector<pair<int, int> >(N);

    FOR(i, N) {
        cin >> cows[i].first >> cows[i].second;
    }

    FOR2R(i, N, 1) {
        cur = cows[i - 1].first;
        j = i;

        while(true) {
            if(cereal_to_cow[cur] == 0) {
                cereal_to_cow[cur] = j;
                cntr++;
                break;
            } else if (cereal_to_cow[cur] < j) {
                break; 
            } else {
                k = cereal_to_cow[cur];
                cereal_to_cow[cur] = j;
                if(cur == cows[k-1].second) {
                    break;
                }
                j = k;
                cur = cows[k - 1].second;
            }
        }

        ans[i] = cntr;
    }

    FOR2(i, 1, N+1) {
        cout << ans[i] << endl;
    }
}