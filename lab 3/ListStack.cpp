#include <bits/stdc++.h>
#include "ListStack.h"

using namespace std;

//metodo constructor
ListStack::ListStack(){
  _head = NULL; //el primer nodo apunta a NULL (es el puntero que va apuntado a la cima del stack)
  _tam = 0;     //el tamaño se inicializa en 0
}

//metodo destructor
ListStack::~ListStack(){
  struct node *ptr;
  while(_head!=NULL){
    ptr = _head;
    _head = _head->next;
    free(ptr);
  }
}

bool ListStack::empty(){
  if(_tam == 0) return true;
  else return false;
}

int ListStack::size(){
  return _tam;
}

int ListStack::top(){
  if(!empty()){
    int top = _head->n;
    return top;
  }
}

void ListStack::push(int dato){ //dato que se va ingresando a la pila
  struct node *nuevo_nodo;
  nuevo_nodo = new node();
  nuevo_nodo->n = dato;
  nuevo_nodo->next = _head;
  _head = nuevo_nodo;
  _tam++;
}

void ListStack::pop(){
  struct node *nodo_auxiliar;
  nodo_auxiliar = _head;
  _head = _head->next;
  delete nodo_auxiliar;
  _tam--;
}
