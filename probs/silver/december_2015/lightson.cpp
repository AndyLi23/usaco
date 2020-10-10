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

int N, M, x, y;
map<pair<int, int>, vector<pair<int, int> > > m;
pair<int, int> temp, temp2;
vector<pair<int, int> > v;

int arr[102][102];

//flood fill-----------
int seen[102][102];

void DFS(int i, int j) {
    if(i > 0 && i <= N && j > 0 && j <= N && seen[i][j] == 0 && arr[i][j] == 1) {
        seen[i][j] = 1;
        temp.first = i;
        temp.second = j;
        v.push_back(temp);

        /*FOR(i, N) {
            FOR(j, N) {
                cout << arr[i+1][j+1] << " ";
            }
            cout << endl;
        }*/

        FOR(k, m[temp].size()) {
            arr[m[temp][k].first][m[temp][k].second] = 1;
        }

        FOR(k, v.size()) {
            x = v[k].first;
            y = v[k].second;

            DFS(x + 1, y);
            DFS(x - 1, y);
            DFS(x, y + 1);
            DFS(x, y - 1);
        }
    }
}

int sum() {
    int ans = 0;
    FOR(i, N)
    {
        FOR(j, N) {
            if(arr[i+1][j+1] == 1) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M;

    FOR(i, M) {
        cin >> temp.first >> temp.second;
        cin >> temp2.first >> temp2.second;

        m[temp].push_back(temp2);
    }

    arr[1][1] = 1;
    DFS(1, 1);

    cout << sum() << endl;
}