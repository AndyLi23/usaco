#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;



int arr[100];
int N = 10;

//binary tree code--------
class Node {
  public:
  int val;
  Node *left, *right;
};


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

//------------------


//preorder---------------------------
void preorder(Node* root) {
  if(root != NULL) {
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

//inorder----------------
void inorder(Node* root) {
  if(root != NULL) {
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
  }
}

//postorder----------------
void postorder(Node* root) {
  if(root != NULL) {
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
  }
}

//-------------------------------------


int main() {
  for(int i = 0; i < N; ++i) {
    arr[i] = i;
  }

  Node* tree = getBinaryTree(0, N-1);

  inorder(tree);
}    