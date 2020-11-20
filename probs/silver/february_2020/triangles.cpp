#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

#define FOR(i, n) for(long long (i) = 0 ; (i) < (n); ++(i))
#define FOR2(i, a, b) for(long long (i) = (a); (i) < (b); ++(i))
#define FOR2R(i, b, a) for(long long (i) = (b); (i) >= (a); --(i))


//RUNNING:
//g++ -O task.cpp

long long N, x[100000], y[100000], xs[100000], ys[100000];

unordered_map<long long, vector<long long> > dpx;
unordered_map<long long, vector<long long> > dpx2;
unordered_map<long long, long long> dpx3;
unordered_map<long long, long long> dpx4;

unordered_map<long long, vector<long long> > dpy;
unordered_map<long long, vector<long long> > dpy2;
unordered_map<long long, long long> dpy3;
unordered_map<long long, long long> dpy4;

unordered_map<long long, vector<long long> > xtoy;
unordered_map<long long, vector<long long> > ytox;


bool cmp(long long i , long long j) {
    return x[i] < x[j];
}
bool cmp2(long long i , long long j) {
    return y[i] < y[j];
}

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N;

    FOR(i, N) {
        cin >> x[i] >> y[i];
        xs[i] = i;
        ys[i] = i;
        xtoy[x[i]].push_back(y[i]);
        ytox[y[i]].push_back(x[i]);
    }

    sort(xs, xs + N, cmp);
    sort(ys, ys + N, cmp2);

    FOR(i, N) {
        long long curx = x[ys[i]];
        long long cury = y[ys[i]];
        if (dpx[curx].size() == 0)
        {
            long long s = 0;
            FOR(j, xtoy[curx].size()) {
                s += xtoy[curx][j] - cury;
            }
            dpx[curx].push_back(s);
            dpx2[curx].push_back(cury);
        }
        else
        {
            dpx[curx].push_back(dpx[curx][dpx3[curx]] + (2 * (dpx3[curx]+1) - xtoy[curx].size()) * (cury - dpx2[curx][dpx3[curx]]));
            dpx2[curx].push_back(cury);
            dpx3[curx]++;
        }


        curx = x[xs[i]];
        cury = y[xs[i]];
        if (dpy[cury].size() == 0)
        {
            long long s = 0;
            FOR(j, ytox[cury].size()) {
                s += ytox[cury][j] - curx;
            }
            dpy[cury].push_back(s);
            dpy2[cury].push_back(curx);
        }
        else
        {
            dpy[cury].push_back(dpy[cury][dpy3[cury]] + (2 * (dpy3[cury]+1) - ytox[cury].size()) * (curx - dpy2[cury][dpy3[cury]]));
            dpy2[cury].push_back(curx);
            dpy3[cury]++;
        }

    }

    long long ans = 0;
    FOR(i, N)
    {
        ans += dpx[x[i]][dpx4[x[i]]] * dpy[y[i]][dpy4[y[i]]];
        dpy4[y[i]]++;
        dpx4[x[i]]++;
    }

    cout << ans % (1000000007) << endl;
}