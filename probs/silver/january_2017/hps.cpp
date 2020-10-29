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

int N, ans;
char moves[100000];

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    map<char, int> counter;
    map<char, int> counter2;
    char temp;

    FOR(i, N) {
        cin >> temp;
        counter[temp]++;

        moves[i] = temp;
    }

    FOR(i, N) {
        counter2[moves[i]]++;
        counter[moves[i]]--;

        ans = max(ans, max(counter['H'], max(counter['P'], counter['S'])) + max(counter2['H'], max(counter2['P'], counter2['S'])));
    }

    cout << ans << endl;
}