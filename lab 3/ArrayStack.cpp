#include <bits/stdc++.h>
#include "ArrayStack.h"

ArrayStack::ArrayStack(){
  _tam = 10; //tamaño original
  _it = 0; //tamaño actual
  _arr = (int*) malloc(_tam*sizeof(int));
}

ArrayStack::~ArrayStack(){
  free(_arr);
}

bool ArrayStack::empty(){
  if(_it == 0) return true;
  else return false;
}

int ArrayStack::size(){
  return _it;
}

int ArrayStack::top(){
  if(_it > 0) return _arr[_it-1];
  else return -1;
}

void ArrayStack::push(int n){
  if(_it < _tam){
    _arr[_it++] = n;
  }
  else{
    _tam = _tam * 2;
    _arr = (int*)realloc(_arr , _tam*sizeof(int));
    _arr[_it++] = n;
  }
}

void ArrayStack::pop(){
  if(_it > 0 ) _it--;
}
