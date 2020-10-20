#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;


LinkedList :: LinkedList (){//crea la LinkedList
 head=NULL;
 select=head;
 tail=NULL;
}
	LinkedList::~LinkedList(){// Destruye la LinkedList
  struct node *ptr;
  while(head!=NULL){// Elimina Nodo a Nodo
    ptr = head;
    head = head->next;
    free(ptr);
  }
}
void LinkedList::insert(int num){// inserta a num al final de la lista
  select=head;
  if(head==NULL){ // si la lista está vacia se inserta la cabeza de la lista 
    head=(struct node*)malloc(sizeof(node));
    head->n=num;
    head->next=NULL;
    tail=head;
   // head->prev=NULL;
  } else{
    if(!search(num)){
      aux=(struct node*)malloc(sizeof(node));
      aux->n=num;
      aux->next=NULL;
      tail->next=aux;
      tail=aux;
    }
  }

}

	void LinkedList :: remove (int num){// Elimina el nodo que contiene a num 
    select=head;
    aux=select;
    if(search(num)){
      if(select==head){ head=select->next;
        free(select);
     }else{aux->next=select->next;
      free(select);}
    }
  }
	bool LinkedList::  search(int num){// Busca a num en la lista
    select=head; 
     while(true){// recorre la lista hasta el
     if(select==NULL){
        return false;
      }
     if(select->n == num){
        return true;
       }
       else{
        aux=select;
        select=select->next;
      }

    }
  }
