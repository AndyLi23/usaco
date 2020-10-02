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
map<int, map<int, int> > one;
map<int, int> counter;
vector<int> arr;

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> temp;
        one[temp][counter[temp]] = i;
        counter[temp]++;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    counter.clear();

    FOR(i, N) {
        ans = max(ans, one[arr[i]][counter[arr[i]]] - i);
        counter[arr[i]]++;
    }

    cout << ans+1 << endl;

}