#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


class myComparator 
{ 
public: 
    int operator() (const int e1, const int e2) 
    { 
        return e1 > e2; 
    } 
}; 

int main() {
    
    //min heap (reverse for max heap)

    priority_queue<int, vector<int>, myComparator> pq;

    pq.push(10);
    pq.push(6);
    if(!pq.empty()) {
        cout << pq.top() << endl;
    }
    pq.pop();

    //queue

    queue<int> q;

    q.push(3);
    q.push(5);
    if(!q.empty()) {
        cout << q.front() << endl;
    }
    q.pop();

    //stack
    stack<int> s;

    s.push(3);
    s.push(5);
    if(!s.empty()) {
        cout << s.top() << endl;
    }
    s.pop();
}