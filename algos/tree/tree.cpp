#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


//----------------------- BINARY INDEX TREE
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 



int main() {
  Tree<int> T;
  T.insert(0);
  T.insert(5);
  //get number of elements less than 3 -> 1
  cout << T.order_of_key(3);
}