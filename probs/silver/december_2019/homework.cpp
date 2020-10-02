#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); (i)++)


//RUNNING:
//g++ -O task.cpp

int N, sum, cnt;
vector<int> ans;
int arr[100000], dp[100000];
float avg, mx;

int main() {
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);

    cin >> N;

    FOR(i, N) {
        cin >> arr[i];
        dp[i] = arr[i];
        sum += arr[i];
    }

    for(int i = N-2; i >= 0; --i) {
        dp[i] = min(dp[i], dp[i+1]);
    }

    cnt = N;
    mx = -1;

    FOR(k, N-2) {
        cnt--;
        sum -= arr[k];

        avg = (float)(sum-dp[k+1])/(float)(cnt-1);

        if(avg > mx) {
            mx = avg;
            ans.clear();
            ans.push_back(k+1);
        } else if (avg == mx) {
            ans.push_back(k+1);
        }
    }

    FOR(i, ans.size()) {
        cout << ans[i] << endl;
    }
}