#include "StackADT.h"

class ArrayStack : public StackADT{
 private:
  int _tam;
  int _it;
  int *_arr;
 public:
  ArrayStack();
  ~ArrayStack();
  bool empty();
  int size();
  int top();
  void push(int);
  void pop();
};
