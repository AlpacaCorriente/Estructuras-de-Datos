#include "PriorityQueueADT.h"

class PriorityQueueHeap : public PriorityQueueADT{

 private:
  int *_arr;
  int _size;
  std::vector<int> Q;
	int it;

 public:
  PriorityQueueHeap();
  ~PriorityQueueHeap();
  bool empty();
  int size();
  int top();
  void push(int);
  void pop();
};
