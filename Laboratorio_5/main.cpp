#include <bits/stdc++.h>
#include <unistd.h>
#include "BinarySearchTree.h"

using namespace std;

int main(){
  BinarySearchTreeADT *bst1 = new BinarySearchTree();
  BinarySearchTreeADT *bst2 = new BinarySearchTree();
  int count;
  cin>> count;
  vector<int>myvector;
  int cant;
  for (int i = 0; i < count; ++i){
  cin>> cant;
  for(int i= 0 ; i<cant;++i) myvector.push_back(i);
  	random_shuffle(myvector.begin(), myvector.end());

  time_t start=clock();
  for(vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it){
  	bst1->insert(*it);}
  	double tiempo=((double)(clock()-start)/CLOCKS_PER_SEC);
  	cout<<endl<<"tiempo de insercion numero random"<<tiempo;
  	
  	start=clock();

  for(int i=0; i<cant ; i++ ){
  	bst2->insert(i);
  }
  	 tiempo=((double)(clock()-start)/CLOCKS_PER_SEC);
  	cout<<endl<< "tiempo de insercion numeros ordenados:"<<tiempo;
  	start=clock();

// random_shuffle(myvector.begin(), myvector.end());
  start=clock();
  for(vector<int>::iterator it=myvector.begin();it!=myvector.end(); ++it){
  	bst1->search(*it);}
  	 tiempo=((double)(clock()-start)/CLOCKS_PER_SEC);
  	cout<<endl<< "tiempo de busquedas numeros random:"<<tiempo;

  start=clock();
  for(vector<int>::iterator it=myvector.begin();it!=myvector.end(); ++it){
  	bst2->search(*it);}
  tiempo=((double)(clock()-start)/CLOCKS_PER_SEC);
  	cout<<endl<< "tiempo de busquedas numero ordenado"<<tiempo<<endl;
  }


  return 0;
}
