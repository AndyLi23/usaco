#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)

const int MAXN = 10000;
int parent[MAXN], size_[MAXN];

void make_set(int v) {
    parent[v] = v;
    size_[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if(size_[a] < size_[b])
            swap(a, b);
        parent[b] = a;
        size_[a] += size_[b];
    }
}

int main() {
    make_set(5);
    make_set(4);
    make_set(6);
    make_set(100);

    union_sets(5, 4);
    union_sets(5, 6);

    cout << size_[find_set(5)];
}