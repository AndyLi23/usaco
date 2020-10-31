#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i, n) for(int (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(int (i) = (b); (i) >= (a); --(i))

int N;
int x[100000], y[100000];
int cid[100000];
int minl[100000];
int maxr[100000];

 
bool cmp(int a,int b) {
	if(x[a]==x[b]) return y[a]<y[b];
	return x[a]<x[b];
}
 
 
int main() {
	freopen("moop.in","r",stdin);
	freopen("moop.out","w",stdout);
	cin >> N;
	FOR(i, N) {
		cin >> x[i] >> y[i];
		cid[i] = i;
	}

	sort(cid,cid+N,cmp);

	minl[0] = y[cid[0]];


	FOR2(i, 1, N) {
		minl[i] = min(minl[i-1], y[cid[i]]);
    }

	maxr[N-1] = y[cid[N-1]];
	FOR2R(i, N-2, 0) {
		maxr[i] = max(maxr[i+1], y[cid[i]]);
    }

	int ans = 1;
	FOR(i, N-1) {
		if(minl[i] > maxr[i+1]) {
			ans++;
        }
    }
	cout << ans << '\n';
}

