#include <bits/stdc++.h>
#include <unistd.h>
#include "ArrayStack.h"
#include "ListStack.h"

using namespace std;


int n;

void print(StackADT *st){
  vector<int> vec;
  cout<<"Size: "<<st->size()<<endl;
  cout<<"Empty? ";
  if(st->empty()) puts("Yes!");
  else puts("No");
  while(!st->empty()){
    vec.push_back(st->top());
    st->pop();
  }
  for(int i=vec.size()-1;i>=0;i--) st->push(vec[i]);
  for(int i=0;i<vec.size();i++) cout<<vec[i]<<endl;
}


int main(){

  srand(time(NULL));
  StackADT *as = new ArrayStack();
  StackADT *ls = new ListStack();

  puts("Cantidad de numeros a insertar");
  cin>>n;

  for(int i = 0; i<n; i++){
    int num = rand()%100;
    as->push(num);
    ls->push(num);
  }

  system("clear");
  puts("ArrayStack");
  print(as);

  puts("\nListStack");
  print(ls);
  puts("");

  return 0;
}
