#include "BinarySearchTreeADT.h"

struct node{
  int num;
  int altura;
  node *padre;
  node *left;
  node *right;
};

class AVLTree: public BinarySearchTreeADT{
 private:
  node *_root;
  int _size;
  void posorder(node*);
  void rotsimplederecha(node*);
  void rotsimpleizquierda(node*);
  void rotdobleizquierda(node*);
  void rotdoblederecha(node*);
  
 public:
  AVLTree();
  ~AVLTree();
  void insert(int);
  node *search(int);
  int size();
 

};
