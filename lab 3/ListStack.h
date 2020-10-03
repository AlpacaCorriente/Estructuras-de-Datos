#include "StackADT.h"

struct node{
  int n;  //dato
  node *next; //puntero al siguiente nodo
};

class ListStack : public StackADT{
 private:
  struct node *_head; //puntero de tipo node
  int _tam;       //tamaño de la pila
 public:
  ListStack();
  ~ListStack();
  bool empty();
  int size();
  int top();
  void push(int);
  void pop();
};
