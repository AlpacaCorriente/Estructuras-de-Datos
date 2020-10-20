#include "MiniSet.h"

struct node{
	int n;
	node *next=NULL;
	//node *prev=NULL;
};

class LinkedList: public MiniSet{
private:
	struct node *head;// cabeza de la lista
	struct node *tail;// cola de la lista
	struct node *select;// puntero que recorre la lista
	struct node *aux;// puntero que almacena el nodo anterior a seleccion
public:
	LinkedList();
	~LinkedList();
	void insert(int num);
	void remove (int num);
	bool search(int num);
	 };