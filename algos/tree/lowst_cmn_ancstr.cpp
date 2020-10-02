#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)


class Node {
  public:
  int val;
  Node *left, *right;
};

int arr[1000];


Node * getBinaryTree(int i, int j) {
  if(i <= j) {
    int m = (i+j)/2;
    Node* root = new Node();
    root->val = arr[m];
    root->left = getBinaryTree(i, m-1);
    root->right = getBinaryTree(m+1, j);

    return root;
  }
  return NULL;
}

//LOWEST COMMON ANCESTOR-----------------

Node *ans;


bool lca(Node* cur, int p, int q) {
    if(cur == NULL) {
        return false;
    }

    bool l = lca(cur->left, p, q);
    bool r = lca(cur->right, p, q);

    bool mid = ((cur->val == p) || (cur->val == q));

    if((mid + l + r) >= 2) {
        ans = cur;
    }

    return (mid || l || r);
}


//----------------------------------



int main() {
    FOR(i, 1000) {
        arr[i] = i;
    }
    Node *tree = getBinaryTree(0, 200);

    lca(tree, 5, 13);

    cout << ans->val << endl;
}