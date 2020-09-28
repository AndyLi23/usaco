#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


//binary tree node--------
class Node {
  public:
  int val;
  Node *left, *right;
};
//------------------



//create binary tree from array---------

//NOTE: J SHOULD BE LEN(ARR)-1
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
//-------------------------



int main() {
  //example usage
  Node *tree = new Node();
  tree->val = 5;
  tree->left = new Node();
  tree->left->val = 10;
  
  cout << tree->left->val << "\n";
}