#include <bits/stdc++.h>
#include "Busqueda.h"

using namespace std;

Busqueda::Busqueda(int n) {
  this->vec = new int[n];
    
  srand(time(NULL));

  for(int i=0;i<n;i++) {
    this->vec[i] = rand() % n + 1;
  }
  this->tam = n;
  sort(this->vec,this->vec + this->tam);
  
  
  for(int i=0;i<this->tam;i++) cout<<this->vec[i]<<" ";
  puts("");
}

Busqueda::~Busqueda(){
  delete this->vec;
}
int Busqueda::size(){
  return this->tam;
}

int Busqueda::lineal(int num){
  for(int i=0;i<tam;i++){
    if (vec[i]==num){
      return vec[i];}

    }
    return -1;

}

int Busqueda::binariaRecursiva(int num,int l,int r){
  if(r>=l){
    int mid=l+(r-l)/2;
    if(vec[mid]==num)return vec[mid];
    if(vec[mid]>num){
      return binariaRecursiva(num,l,mid-1);
    }
    else{
      return binariaRecursiva(num,mid+1,r );
    }
  }
  return -1;
}

int Busqueda::binariaIterativa(int num){
  int inf = 0; //cota inferior 
   int  sup=tam;// cota superior
    int mid=0;
   while ((inf+1 )!= sup){
    mid=(inf+sup)/2;
      if(vec[mid]==num){
        return vec[mid];
      }

    if(vec[mid]<num){
        inf = mid;
        mid=(inf+sup)/2;
      }
    if(vec[mid]>num){
        sup =mid;
        mid=(inf+sup)/2;
      }
  
    }
   return -1;


}
