#include "BinarySearchTreeADT.h"

struct node{
  int num;
  node *left;
  node *right;
};

class BinarySearchTree: public BinarySearchTreeADT{
 private:
  node *_root;
  int _size;
  void posorder(node*);

 public:
  BinarySearchTree();
  ~BinarySearchTree();
  void insert(int);
  node *search(int);
  int size();
 

};
