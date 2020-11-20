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

int N, M, K, t1, t2;
int arr[100000], cycleNums[100000], pos[100000], ans[100000];
pair<int, int> swaps[100];
vector<int> cycles[100000];

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M >> K;

    FOR(i, M) {
        cin >> t1 >> t2;
        t1--;
        t2--;
        swaps[i] = make_pair(t1, t2);
    }

    FOR(i, N) {
        arr[i] = i;
        FOR(j, M) {
            if(swaps[j].first <= arr[i] && swaps[j].second >= arr[i]) {
                arr[i] = swaps[j].first + swaps[j].second - arr[i];
            }
        }
    }

    int cycleNum = 1;
    FOR(i, N) {
        if(!cycleNums[i]) {
            cycleNums[i] = cycleNum;
            cycles[cycleNum].push_back(i);
            int j = arr[i];
            if(i != j) {
                pos[j] = 1;
            }

            while(j != i) {
                cycles[cycleNum].push_back(j);
                cycleNums[j] = cycleNum;
                if(j != arr[j]) {
                    pos[arr[j]] = pos[j] + 1;
                }
                j = arr[j];
            }

            cycleNum++;
        }
    }

    FOR(i, N) {
        ans[cycles[cycleNums[i]][(pos[i] + K) % cycles[cycleNums[i]].size()]] = i;
    }

    FOR(i, N) {
        cout << ans[i] + 1 << endl;
    }
}