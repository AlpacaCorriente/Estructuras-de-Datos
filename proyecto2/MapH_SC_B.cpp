#include <bits/stdc++.h>
#include "MapH_SC_B.h"

using namespace std;

//inicia un mapa vacio
MapH_SC_B::MapH_SC_B(int cant) {
    n = 0;
    m=cant*2;//calcula el tamaño de la tabla respecto al factor de carga 
    tabla =  new struct node* [m];
    for (int i=0;i<m; i++ ){// inicializa una tabla en NULL
      tabla[i]=NULL;
    }

  }
   MapH_SC_B::~MapH_SC_B(){
    struct node *it , *next;
      for (int i=0;i<m; i++ ){
         it=tabla[i];
         while(it != NULL){
          next=it->next;
          delete(it);
          it=next;
        }
    }
    delete(tabla);

   }
int MapH_SC_B::size(void) {// retorna la cantidad de 
return n;
}
bool MapH_SC_B::isEmpty(void) {// retorna si está vacio
return size() == 0;
}


int MapH_SC_B::hash(string clave){// realiza la funcion de hash , 
    char val;
    int valor;
    val=clave[0];
    valor=val;
    return valor %m;


}
void MapH_SC_B::put(pair<string , int> v) {// inserta un par en la tabla
	int i = hash(v.first);
  if(tabla[i] != NULL){//si hay pares insertados en esa posicion se inserta al final de la lista asociada  
     struct node *it =tabla[i];// puntero que recorre la lista asociada  a la posicion  
     while (it != NULL){// recorre la lista en la posicion hasta el final
          if(v.first.compare(it->kv.first)==0)break;// si ya existe el elemento no se inserta
          if(it->next==NULL){// insercion al final 
            struct node *aux;
            aux= new struct node;
            aux->kv.first=v.first;
            aux->kv.second=v.second;
            aux->next=NULL;
            it->next=aux;
            it=aux;
            n++;
           }
              it=it->next;
           }
          }
  else{//insercion del primer elemento en la posicion i de la tabla
    tabla[i]= new struct node;
    tabla[i]->kv.first=v.first;
    tabla[i]->kv.second=v.second;
    tabla[i]->next=NULL;
          n++;
        } 
}
void MapH_SC_B::putRH(pair<string , int> v) {
  put(v);// para el re hashing inserta primero el par a la tabla 
  if(0.75<(double)n/m){// si la densidad de los datos es mayor a 0.75(maxima densidad) hace rehashing 
    int tam = m;// se guarda el tamaño antiguo de la tabla
    m=m*2;// el tamaño de la tabla se multiplica por 2
    struct node** t_aux = tabla;
    tabla = new struct node* [m];// crea una tabla doble del tamaño anterior
    n=0;
   for (int i=0;i<m; i++ ){// inicializa una tabla en NULL
      tabla[i]=NULL;
    }
    for(int i=0; i<tam;i++ ){// transfiere los pares antiguos a la nueva tabla 
      struct node *it , *next;
      if(t_aux[i]!=NULL){
        it=t_aux[i];
      while(it != NULL){// recorre la lista de cada posicion y hace rehashing de cada par 
         next=it->next;
         put(make_pair (it->kv.first, it->kv.second));
         delete(it);// elimina cada nodo de la tabla antigua 
         it=next;
        }
      }
    }
    delete(t_aux);// finalmente elimina la referencia de la antigua tabla
  }

}
 

/*obtiene el valor asiciado de una clave ya insertada*/
int MapH_SC_B::get(string clave) {
  int i=hash(clave);// hace el hash  del string para saber donde comenzar la busqueda
  if(tabla[i] != NULL){// si hay una lista asociada a la posicion i
    struct node *it =tabla[i];
     while (it != NULL){// se comineza la busqueda nodo a nodo  hasta el final 
          if(clave.compare(it->kv.first)==0){// si coincide lo buscado con lo insertado , retorna el valor asociado a la clave
            return it->kv.second;
           }
             it=it->next;
           }
           return -1;

  }else return-1; 
}

//Devuelve el valor asociado con la clave especificada e elimina la clave
int MapH_SC_B::remove(string clave) {
  int i=hash(clave);
  if(tabla[i] !=NULL){// si hay nodos insertados en la pasicion i , se revisa si está la clave a elimiar
    struct node *it=tabla[i];// puntero que recorre la lista
    struct node *prev;// guarda el nodo anterior
    struct node *head;// guarda el primer nodo asociado a la posicion i 
    head=it;
    prev=it;
   while(it != NULL){
    int val;
    if(clave.compare(it->kv.first)==0){// si coinciden las claves , elimina el par clave-valor
       if(it==head){
       /* si es el primer elemento asociado a la posicion se  elimina el par y se conecta el resto de la lista a la posicion i*/
        val=it->kv.second;
        head=it->next;
        tabla[i]=head;
        delete(it);
        return val;
       }
       else{
         struct node * aux;
         val=it->kv.second;
         aux=it->next;
         prev->next=aux;
         delete(it);
         return val;
      }
    }
     prev=it;
     it=it->next;
    }
    return -1;// retona valor -1 si no se encuentra la clave en la lista

  }else return -1; 
} 
int MapH_SC_B::removeRH(string clave) {
   remove(clave);// retira la clave
  if(0.5>(double)n/m){// mira si el factor de carga es menor a 0.5 si es así realiza rehashing 
  
   int tam = m;// guarda el tamaño de la tabla antigua 
    m=m/2; // reduce el tamaño a la mitad
    struct node** t_aux = tabla;// la tabla actual es respaldada
    tabla = new struct node* [m];// crea una nueva tabla con tamaño m/2 
    n=0;
   for (int i=0;i<m; i++ ){// inicializa una tabla en NULL
      tabla[i]=NULL;
    }
    for(int i=0; i<tam;i++ ){// hace rehashing de todos los pares insertados en la tabla 
      struct node *it , *next;
      if(t_aux[i]!=NULL){// recorre las listas de cada posicion 
        it=t_aux[i];
      while(it != NULL){
         next=it->next;
         put(make_pair (it->kv.first, it->kv.second));// inserta los pares en la nueva tabla
         delete(it);
         it=next;
        }
      }
    }
    delete(t_aux);
  }

}

