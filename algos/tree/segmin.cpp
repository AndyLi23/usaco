#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))
#define ll long long

int N = 8;
int a[8]{5, 8, 6, 3, 2, 3, 2, 6};
int tree[200000]; //size should be at least 2N

//**** ALL PARAMETERS ARE 0-INDEXED *****
//min from range a to b
int getmin(int a, int b) {
    a += N; b += N;
    int s = INT_MAX;
    while(a <= b) {
        if(a%2==1) s = min(s, tree[a++]);
        if(b%2==0) s = min(s, tree[b--]);
        a /= 2; b /= 2;
    }
    return s;
}

//add x to element at index k
void add(int k, int x) {
    k += N;
    tree[k] += x;
    for (k /= 2; k >= 1; k/=2) {
        tree[k] = min(tree[2 * k], tree[2 * k + 1]);
    }
}

//initialize with another array a (size should be N)
void init(int a[]) {
    FOR2(i, N, 2*N) {
        tree[i] = a[i - N];
    }
    FOR2R(i, N-1, 1) {
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
}

int getind(int a) {
    return tree[N + a];
}

void setelement(int k, int x) {
    add(k, x - getind(k));
}

int main() {
    init(a);
    add(5, 4);

    FOR(i, 2*N) {
        cout << tree[i] << " ";
    }
    cout << endl << getmin(0,2);
}