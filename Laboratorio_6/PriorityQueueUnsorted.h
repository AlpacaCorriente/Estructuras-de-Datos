#include "PriorityQueueADT.h"

class PriorityQueueUnsorted : public PriorityQueueADT{

 private:
  int *_arr;
  int _size;

 public:
  PriorityQueueUnsorted();
  ~PriorityQueueUnsorted();
  bool empty();
  int size();
  int top();
  void push(int);
  void pop();
};
