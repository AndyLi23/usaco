#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp



int N, D, b[200000], e[200000], a[200000], dist[200000];

struct comp2 {
    bool operator() (int i, int j) const {
        return b[i] < b[j];
    }
};

struct comp {
    bool operator() (int i, int j) const {
        return e[i] < e[j];
    }
};
queue<int> q;
multiset<int, comp> sB;
multiset<int, comp2> sE;

multiset<int, comp>::iterator itB;
multiset<int, comp2>::iterator itE;

int main() {
    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> D;

    FOR(i, 2*N) {
        cin >> b[i] >> e[i];
        b[i] = -b[i];
        e[i] = -e[i];
        a[i] = i;
    }

    fill(dist, dist+2*N, -1);

    FOR(i, N) {
        if(e[i] == 0) {
            q.push(i);
            dist[i] = 1;
        } else {
            sB.insert(i);
        }

        if(b[N+i] == 0) {
            q.push(N+i);
            dist[N+i] = 1;
        } else {
            sE.insert(N+i);
        }
    }

    while(!q.empty()) {
        int i = q.front();
        q.pop();


        if(i < N) {
            while(true) {
                itE = sE.lower_bound(i);
                if(itE == sE.end() || b[*itE] > b[i]+D) {
                    break;
                }
                dist[*itE] = dist[i]+1;
                q.push(*itE);
                sE.erase(itE);
            }
        } else {
            while(true) {
                itB = sB.lower_bound(i);
                if(itB == sB.end() || e[*itB] > e[i]+D) {
                    break;
                }
                dist[*itB] = dist[i]+1;
                q.push(*itB);
                sB.erase(itB);
            }
        }


    }

    FOR(i, N) {
        cout << dist[i] << endl;
    }

}