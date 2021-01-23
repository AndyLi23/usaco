#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N;
int x[1000], y[1000], earr[1000], narr[1000], e, n, stoppedx[1000], stoppedy[1000], blame[1000], blame2[1000];
bool stopped[1000];
char temp;

bool compe(int i, int j) {
    return y[i] < y[j];
}

bool compn(int i, int j) {
    return x[i] < x[j];
}

int main() {
    //comment out for submission
    //freopen("3.in", "r", stdin);
    //freopen("3.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;
    FOR(i, N) {
        cin >> temp;
        cin >> x[i] >> y[i];
        if(temp == 'E') {
            earr[e] = i;
            e++;
        }
        if(temp == 'N') {
            narr[n] = i;
            n++;
        }
    }

    sort(earr, earr+e, compe);
    sort(narr, narr + n, compn);

    FOR(i, e) {
        int cure = earr[i];
        FOR(j, n) {
            int curn = narr[j];
            if(x[curn] > x[cure] && y[cure] > y[curn] && x[curn] - x[cure] < y[cure] - y[curn]) {
                if(!stopped[cure] && !stopped[curn]) {
                    stopped[curn] = 1;
                    blame[cure] += blame[curn] + 1;
                }
            }


            if(x[curn] > x[cure] && y[cure] > y[curn] && x[curn] - x[cure] > y[cure] - y[curn]) {
                if(!stopped[curn] && !stopped[cure]) {
                    stopped[cure] = 1;
                    blame[curn] += blame[cure] + 1;
                }
            }
        }
    }

    FOR(i, N) {
        cout << blame[i] << endl;
    }
}