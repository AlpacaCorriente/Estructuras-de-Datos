#include <bits/stdc++.h>
#include "Queue.h"

using namespace std;

int main(){
  QueueADT *que1 = new Queue();
  queue<int> que2;
  int count;
  cin>> count;
    double tiempo;
  time_t start= clock();
  cout<<"comparacion de tiempos de operaciones"<<endl;
  for (int i = 0; i < count; ++i){
  	que1->push(i);
  }
  tiempo =((double)clock()-start)/CLOCKS_PER_SEC; 
  cout<<"tiempo de push implementacion con 2 colas:"<<tiempo<<endl;
    start= clock();
   for (int i = 0; i < count; ++i){
  	que2.push(i);
  }
  tiempo =((double)clock()-start)/CLOCKS_PER_SEC; 
  cout<<"tiempo de push implementacion STL:"<<tiempo<<endl;

  start= clock();


  for (int i = 0; i < count; ++i){
  	que1->pop();
  }
   tiempo =((double)clock()-start)/CLOCKS_PER_SEC; 
  cout<<"tiempo de pop implementacion 2 colas:"<<tiempo<<endl;
   start= clock();

  for (int i = 0; i < count; ++i){
  	que2.pop();}
  tiempo =((double)clock()-start)/CLOCKS_PER_SEC; 
  cout<<"tiempo de pop implementacion STL:"<<tiempo<<endl;

  return 0;
}
