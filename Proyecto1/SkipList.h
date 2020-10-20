#include "MiniSet.h"

struct nodo
{ int val; //valor que contiene el nodo
	nodo *next=NULL;//  nodo siguiente 
	nodo *prev=NULL;// nodo anterior 
	nodo *up=NULL;// nodo superior 
	nodo *down=NULL;// nodo inferor 
	
};
class SkipList : public MiniSet{
private:
	int level;// cantidad de niveles en la skiplist
	struct nodo *Lmin;//apunta al limite inferior del tope de la skiplist  
	struct nodo *Lmax;// apunta al limite superior del tope de la skiplist
	struct nodo *seleccion;// puntero que se ocupa de recorrer la skiplist 
	struct nodo *aux;// puntero que acompaña para recorrer los niveles horizontalmente , apunta la mayoria de las veces al elemento siguiente de seleccion
    struct nodo *downprev;//puntero que es utilizado para recorrer los niveles de la skiplist , acompaña al puntero seleccion apuntando al nodo que esta en el nivel inferior 

	void addnodo(int);// agrega nodo en la posición donde está el puntero seleccion
	void addLevel(int);// agrega niveles despues del tope del skiplist

public : 
SkipList();
~SkipList();
void insert(int);
void remove(int);
bool search(int);
void imprimir();
};