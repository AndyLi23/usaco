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
class myComparator { 
public: 
    int operator() (const vector<int> e1, const vector<int> e2) 
    { 
        return e1[0] > e2[0]; 
    } 
}; 


int N, G, ans;
priority_queue<vector<int>, vector<vector<int> >, myComparator> pq;
map<int, int, greater<int> > cnts;
map<int, int> cows;

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> G;

    vector<int> temp;

    FOR(i, 3) {
        temp.push_back(0);
    }

    FOR(i, N) {
        cin >> temp[0] >> temp[1] >> temp[2];
        pq.push(temp);
    }

    while(!pq.empty()) {
        temp = pq.top();
        pq.pop();

        int ref = cows[temp[1]];

        bool wastop = ref == cnts.begin()->first;
        
        int wascnt = cnts[ref];

        if(wascnt == 1) {
            cnts.erase(ref);
        } else {
            cnts[ref]--;
        }

        cows[temp[1]] += temp[2];

        ref = cows[temp[1]];

        cnts[ref]++;

        int iscnt = cnts[ref];
        bool istop = ref == cnts.begin()->first;

        //cout << wascnt << " " << iscnt  << " " << wastop << " " << istop << endl;

        if(wastop)  {
            if(!istop || wascnt != 1 || iscnt != 1) {
                ans++;
            }
        } else if (istop) {
            ans++;
        }

    }

    cout << ans << endl;

    
}