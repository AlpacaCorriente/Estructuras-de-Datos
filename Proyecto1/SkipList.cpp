
#include <bits/stdc++.h>
#include "SkipList.h"
using namespace std;
SkipList::SkipList (){// construye dos listas vacias con los nodos infinitos en sus extremos , una es la base de la skiplist donde están todas las keys y la otra es el nivel final

Lmax=(struct nodo*)malloc(sizeof(nodo));// crea la lista de la base 
Lmin=(struct nodo*)malloc(sizeof(nodo));
Lmin->val=INT_MIN;
Lmax->val=INT_MAX;
Lmin->down=NULL; Lmin->prev=NULL;
Lmax->down=NULL; Lmax->next=NULL;
Lmax->prev=Lmin;// enlazado de limite inferior y superior de la base
Lmin->next=Lmax;
aux=(struct nodo*)malloc(sizeof(nodo));// se crea la lista tope que está sobre la base enlazando los limites del stack (infinito positivo y negativo) 
aux->val=INT_MAX; aux->next=NULL; 
aux->down=Lmax; Lmax->up=aux;
Lmax=aux;
aux=(struct nodo*)malloc(sizeof(nodo)); 
aux->val=INT_MIN; aux->prev=NULL; 
aux->down=Lmin; Lmin->up=aux;
Lmin=aux;
Lmax->prev=Lmin;
Lmin->next=Lmax; 
level=0;// cantidad de niveles en la skip list es 0
seleccion=Lmin;
}
SkipList :: ~SkipList(){// Destruye cada nivel de la SkipList y su contenido
	    seleccion=Lmin;
		Lmin=Lmin->down;
		aux=seleccion->next;
		while(seleccion != NULL){
		  if(aux->next != NULL){
		    seleccion=aux->next;
			free(aux);
			aux=seleccion;}
		else{
			free(aux);
			seleccion=Lmin;
			Lmin=Lmin->down;
			aux=seleccion->next;
		}


	}
}
void SkipList:: insert(int num){//variable num es el numero a insertar por el metodo en la skiplist
	int Lcant=0;//cantidad de niveles a insertar con num 
	bool m=true;
	downprev=NULL;
	 srand (time(NULL));//cambia la semilla 
	while(m){//lanzamos "monedas ""
	int f;
	f=rand()%1000;
   if( f%2 == 0){
   	Lcant++;
   }else{ m=false;
   }
	}
	int diflevel=(Lcant-level);//calcula la diferencia de niveles entre los actuales que tiene la skiplist y los a insertar

	if(diflevel>0){//Sí la cantidad de niveles actuales es menor a las que ocupará el numero a insertar , inserta los niveles faltantes
	       if(!search(num)){// si el numero no está insertado en la skiplist comineza la inserción
	       	addLevel(diflevel);//agregar niveles faltantes
	       	search(num);
			addnodo(num);// insertar nodo en la lista base 
			for(int i = 0; i < Lcant; i){//insertar nodos en los niveles 
             if(seleccion->up != NULL){
					seleccion=seleccion->up;
					aux=seleccion->next;
				  addnodo(num);
				  i++;
				}
				else{

					seleccion=seleccion->prev;

				}
			}
		}
	}
	if(diflevel<=0){// si la cantidad de niveles de la skipList es mayor que necesita la insercion, no se agregan mas niveles 
		if(!search(num)){// verifica si el numero ya está insertado
			addnodo(num);//inserta el numero en la base de la skipList
			for (int i = 0; i < Lcant; i){ // inserta el numero en los niveles de la skip list
				if(seleccion->up != NULL){
					seleccion=seleccion->up;
					aux=seleccion->next;
					addnodo(num);
					i++;
				}
				else{

					seleccion=seleccion->prev;
				}
			}
		}

	}

}
void SkipList::remove(int num){// Metodo que elimina el numero almacenado en la variable num y todos los nodos que estan en los niveles asociado a el
struct nodo *auxprev; // Este puntero es creado para almacenar la posicion anterior al nodo a eliminar 
	if(search(num)){// Busca si está el numero a eliminar
		//comienza desde el  nodo  base y luego se van eliminando los niveles en donde está insertado
		        auxprev=seleccion->prev;
				auxprev->next=aux;
				aux->prev=auxprev;
				free (seleccion);// libera el nodo de la base que contiene a num
				seleccion=auxprev;

	while(seleccion != Lmin){//se eliminan todos los nodos que contienen a num en los niveles desde la base hasta el tope
		if(seleccion->up!=NULL){//si el puntero está en el tope de la  skiplist se detiene el borrado 
				seleccion=seleccion->up;
				aux=seleccion->next;
		    if(aux->val==num){//si el puntero aux apunta al nodo en donde está num se elimina del nivel
			auxprev=aux->next;
			seleccion->next=auxprev;
			auxprev->prev=seleccion;
			free(aux);
			aux=seleccion->next;
				}
			} else{
				seleccion=seleccion->prev;
			}
			

		}
	}
	  seleccion=Lmin->down;
	  aux=seleccion->next;
	  while(seleccion->down!=NULL && aux==Lmax->down ){// busca niveles vacios y los borra(los niveles vacios son cuando se selecciona el inicio del nivel y el siguiente elemento es el infinito positivo) 
			auxprev=seleccion->down;
			auxprev->up=Lmin;
			Lmin->down=auxprev;
			free(seleccion);
			auxprev=aux->down;
			Lmax->down=auxprev;
			auxprev->up=Lmax;
			free(aux);
			seleccion=Lmin->down;
			aux=seleccion->next;
			level--;
			}

}
bool SkipList :: search(int num){//Busca a num e indica si está en la base de la skiplist
	seleccion=Lmin;// La busqueda comineza seleccionando el limite inferior de la lista que está en el tope
	aux=seleccion->next;
	while(seleccion->val !=INT_MAX){
		if(seleccion->val<=num && aux->val>num){// si seleccion es un numero menor al buscado y aux es un numero mayor , busca si el numero está entre esos dos     
			if(seleccion->down==NULL && aux->val != num && seleccion->val !=num){ // si seleccion está en la base y el elemento siguiente no es el numero buscado  retorna false
		     	return false;}
		     if(seleccion->down==NULL && seleccion->val == num ){//si seleccion está en la base y el elemento siguiente es el numero buscado , se retorna true 
				return true;
			}
			seleccion=seleccion->down;
			aux=seleccion->next;
		}
		else{
			seleccion=aux;
			aux=seleccion->next;
		}

	}
	// al finalizar search los punteros seleccion y aux quedan en la base de la lista  ya sea para utilizar addnodo o remove;
}
void SkipList:: addnodo( int num ){// agrega un nodo entre el puntero seleccion y aux;
	        struct nodo *add;
			add=(struct nodo*)malloc(sizeof(nodo));
			add->up = NULL;
			add->val=num;
			seleccion->next=add;
			add->prev=seleccion;
			aux->prev=add;
			add->next=aux;
			if(seleccion->down != NULL ){
				add->down=downprev;
				downprev->up=add;
				downprev=add;
			}else{
				add->down=NULL;
				add->up=NULL;
				downprev=add;
			}


}
void SkipList:: addLevel(int Cant){//añade niveles despues del tope, cant es la cantidad de niveles a agregar , y el limite inferior y superior quedan apuntando al nuevo tope
 for(int i =0; i<Cant;i++){
			seleccion=(struct nodo*)malloc(sizeof(nodo));//Pide memoria para el Liminte superior
			seleccion->val=INT_MAX;
			seleccion->down=Lmax; seleccion->next=NULL;
			Lmax->up=seleccion;
			Lmax=seleccion;
			seleccion=(struct nodo*)malloc(sizeof(nodo));// Pide memoria para le limite inferior y se une el Limite inferior con el superior del nuevo nivel
			seleccion->val=INT_MIN;
			seleccion->down=Lmin; seleccion->prev=NULL;
			Lmin->up=seleccion;
			Lmin=seleccion;
			Lmin->next=Lmax;
			Lmax->prev=Lmin;
			level++;
			seleccion=Lmin;
		}
}
