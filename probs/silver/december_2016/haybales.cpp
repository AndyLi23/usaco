#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

int N,Q,temp,temp1, special, ende;

unordered_map<int, int> m;

set<int> s;

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> Q;

    FOR(i, N) {
        cin >> temp;
        s.insert(temp);
    }

    special = *s.begin();
    ende = *s.rbegin();

    for(set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        m[*it] = temp1;
        temp1++;
    }

    FOR(i, Q) {
        cin >> temp >> temp1;    

        int ind1, ind2;

        if((temp < special && temp1 < special) || (temp > ende && temp1 > ende) || (temp == temp1 && temp != special && m[temp] == 0)) {
            cout << 0 << endl;
        } else {

            if(temp == special || m[temp] != 0) {
                ind1 = m[temp];
            } else {
                ind1 = m[*s.lower_bound(temp)];
            }

            if(temp1 == special || m[temp1] != 0) {
                ind2 = m[temp1];
            } else {
                if(temp1 > ende) {
                    ind2 = N - 1;
                }
                else
                {
                    ind2 = m[*s.lower_bound(temp1)]-1;
                }
            }

    
            cout << ind2 - ind1 + 1 << endl;
        }
    }
}