#include "QueueADT.h"
#include <stack>

class Queue : public QueueADT{
 private:
  std::stack<int> _st1,_st2;
 public:
  Queue();
  ~Queue();
  bool empty();
  int size();
  int front();
  int back();
  void push(int);
  void pop();
};
