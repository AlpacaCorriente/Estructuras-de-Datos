#include <bits/stdc++.h>
#include "PriorityQueueHeap.h"
#include "PriorityQueueUnsorted.h"

using namespace std;

void HeapSort(vector<int> &vec){
}

void SelectionSort(vector<int> &vec){
}

int main(){
  PriorityQueueADT *pqh = new PriorityQueueHeap();
  PriorityQueueADT *pqu = new PriorityQueueUnsorted();
  int cant;
  cin>>cant;
  for (int i = 0; i <cant; ++i)
   {int n;
   	cin>>n;

   	pqh->push(n);
   } 

   for (int i = 0; i <cant; ++i)
   	{int n;
   	cin>>n;
if(n==1){
   	pqh->pop();
   }
   } 

  
  
  return 0;
}
