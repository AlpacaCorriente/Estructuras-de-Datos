#ifndef BST_H
#define BST_H

struct node;

class BinarySearchTreeADT {

 public:
  virtual void insert(int) = 0;
  virtual node* search(int) = 0;
  virtual int size() = 0;

};

#endif
