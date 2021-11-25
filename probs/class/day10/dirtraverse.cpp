#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long
#define pb push_back
#define MOD 1000000007;
const int MAXN = 2e5;

int N, parent[100000], cost[100000], numLeaves[100000];
ll downCost[100000], upCost[100000];
vector<int> children[100000];
int leaves;

string temp;
int a, b;

void dfs1(int curNode) {
    if(children[curNode].size() != 0) {
        for(auto child : children[curNode]) {
            dfs1(child);
            if(children[child].size() == 0) {
                numLeaves[curNode]++;
                downCost[curNode] += cost[child];
            } else {
                numLeaves[curNode] += numLeaves[child];
                downCost[curNode] += numLeaves[child] * (cost[child] + 1) + downCost[child];
            }
        }
    } else {
        leaves++;
    }
}

void dfs2(int curNode, int parent) {
    if(children[curNode].size()) {
        if(parent != -1) {
            upCost[curNode] += 3 * (leaves - numLeaves[parent]) + upCost[parent];
            //                       ../ times number of leaves                     downcost of parent without this downcost
            upCost[curNode] += 3 * (numLeaves[parent]-numLeaves[curNode]) + downCost[parent] - downCost[curNode] - numLeaves[curNode] * (cost[curNode]+1);
        }

        for(auto child : children[curNode]) {
            dfs2(child, curNode);
        }
    }
}

int main() {
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //use cin >> and cout <<
    //run local: g++ -std=c++11 -O2 -Wall task.cpp -o a / DONT USE UNORDERED MAP!!!!!

    cin >> N;

    FOR(i, N) {
        cin >> temp >> a;
        cost[i] = temp.length();
        FOR(j, a) {
            cin >> b; b--;
            children[i].pb(b);
        }
    }

    dfs1(0);

    dfs2(0, -1);

    ll ans =LLONG_MAX;

    FOR(i, N) {
        if(children[i].size()) {
            ans = min(ans, downCost[i] + upCost[i]);
        }
    }

    cout << ans << endl;
}