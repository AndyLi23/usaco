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

class Cow {
    public:
    int arrive, time, i;
};

class myComparator { public: int operator() (const Cow& e1, const Cow& e2) { return e1.arrive < e2.arrive; } }; 

class myComparator2 { public: int operator() (const Cow& e1, const Cow& e2) { return e1.i > e2.i; } }; 

priority_queue<Cow, vector<Cow>, myComparator2> pq;


int N, ans;
Cow cows[100005], temp;

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;
    temp = Cow();

    FOR(i, N) {
        cin >> temp.arrive >> temp.time;
        temp.i = i;
        cows[i] = temp;
    }

    sort(cows, cows + N, myComparator());

    int i = 0, curTime = 0;
    while(i < N) {
        pq.push(cows[i]);
        curTime = cows[i].arrive;
        i++;

        while(!pq.empty()) {
            temp = pq.top();
            pq.pop();

            ans = max(ans, curTime - temp.arrive);
            curTime += temp.time;
            while(i < N && cows[i].arrive <= curTime) {
                pq.push(cows[i]);
                i++;
            }
        }
    }

    cout << ans << endl;
}