#include "tree.h"
#include <iostream>
using namespace std;
template <typename T>
bool compare(T value1, T value2)
{
    return value1 > value2;
}
int main() {             
    tree<int> t;
    t.add_node(nullptr, 15);//radacina 15
    t.add_node(t.root, 23);
    t.add_node(t.root, 20);
    t.add_node(t.root, 4);
    cout << t.get_node(t.root, 1).value << endl;
    t.add_node(t.root->child[0], 5);
   // cout << t.get_node(t.root->child[0],0);
    t.sort(t.root, compare);
    cout << t.get_node(t.root, 0).value << " ";
    cout << t.get_node(t.root, 1).value << " ";
    cout << t.get_node(t.root, 2).value;
    t.delete_node(t.root->child[0]);
    t.find(t.root, 20);
  //  cout << t.count(nullptr);
   // cout << endl;
   // cout << t.get_node(t.root,0).value;
   // cout << endl;
  //  t.delete_node(t.root->child[0]);
   // cout << t.get_node(t.root, 0).value;
    //cout << t.get_node(t.root->child[0]).value;
   // cout << t.count(t.root);
    //cout << t.get_node(t.root).value;
}