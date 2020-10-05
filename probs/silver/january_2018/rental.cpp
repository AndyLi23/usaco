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

class Shop {
    public:
    long long quantity, price;
};

class myComparator { 
    public: 
    int operator() (const Shop& e1, const Shop& e2) { 
        return e1.price > e2.price; 
    } 
}; 

int N, M, R, curShop;
long long cows[100005], rentals[100005], milkPrice[100005];
long long ans;
Shop shops[100005], temp;

long long rentalMoney(int i) {
    if(i == 0)
        return 0;
    if(i > R) {
        return rentals[R - 1];
    }
    return rentals[i - 1];
}

int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    //use cin >> and cout <<

    cin >> N >> M >> R;

    FOR(i, N) {
        cin >> cows[i];
    }

    FOR(i, M) {
        temp = Shop();
        cin >> temp.quantity >> temp.price;
        shops[i] = temp;
    }

    FOR(i, R) {
        cin >> rentals[i];
    }

    sort(cows, cows + N, greater<int>());
    sort(rentals, rentals + R, greater<int>());
    sort(shops, shops + M, myComparator());

    FOR2(i, 1, R) {
        rentals[i] += rentals[i - 1];
    }

    FOR(i, N) {
        milkPrice[i+1] = milkPrice[i];
        while(cows[i] != 0 && curShop < M) {
            if(cows[i] < shops[curShop].quantity) {
                milkPrice[i+1] += shops[curShop].price * cows[i];
                shops[curShop].quantity -= cows[i];
                cows[i] = 0;
            } else {
                milkPrice[i + 1] += shops[curShop].price * shops[curShop].quantity;
                cows[i] -= shops[curShop].quantity;
                shops[curShop].quantity = 0;
                curShop++;
            }
        }
    }


    FOR(i, N+1) {
        ans = max(ans, milkPrice[i] + rentalMoney(N-i));
    }

    cout << ans << endl;

    
}