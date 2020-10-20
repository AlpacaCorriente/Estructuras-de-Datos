#include <bits/stdc++.h>
#include "MapH_SC_PA.h"

using namespace std;

//inicia un mapa vacio
MapH_SC_PA::MapH_SC_PA(int cant) {
    n = cant*2;
    m=cant;//calcula el tamaño de la tabla respecto al factor de carga 
    tabla =  new struct nodo* [m];
    for (int i=0;i<m; i++ ){// inicializa una tabla en NULL
      tabla[i]=NULL;
    }

  }
  MapH_SC_PA::~MapH_SC_PA(){
    struct nodo *it , *next;
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
int MapH_SC_PA::size(void) {// retorna el tamaño de carga 
return n;
}
bool MapH_SC_PA:: isEmpty(void) {// retorna si está vacio
return size() == 0;
}


int MapH_SC_PA::hash(string clave){// realiza la funcion de hash , 
 int h=0;
  for (int i = 0; i<clave.length(); ++i)
  {
    h=(31*h + (int) clave[i])%m;
  }
  return h;
}
// cambia el tamaño de la tabla hash a la capacidad dada volviendo a mezclar todas las claves


void MapH_SC_PA::put(pair<string , int> v) {
	int i = hash(v.first);
  if(tabla[i] != NULL){//si hay pares insertados en esa posicion se inserta al final de la lista asociada  
     struct nodo *it =tabla[i];// puntero que recorre la lista asociada a la  posicion  
     while (it != NULL){// se llega hasta el final
          if(v.first.compare(it->kv.first)==0)break;// si ya existe el elemento no se inserta
          if(it->next==NULL){// insercion al final 
            struct nodo *aux;
            aux= new struct nodo;
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
    tabla[i]= new struct nodo;
    tabla[i]->kv.first=v.first;
    tabla[i]->kv.second=v.second;
    tabla[i]->next=NULL;
          n++;
        } 
}
void MapH_SC_PA::putRH(pair<string , int> v) {
  put(v);// para el re hashing inserta primero el par a la tabla 
  if(0.75<(double)n/m){// si la densidad de los datos es mayor a 0.75(maxima densidad) hace rehashing 
    int tam = m;// se guarda el tamaño antiguo de la tabla
    m=m*2;// el tamaño de la tabla se multiplica por 2
    struct nodo** t_aux = tabla;
    tabla = new struct nodo* [m];// crea una tabla doble del tamaño anterior
    n=0;
   for (int i=0;i<m; i++ ){// inicializa una tabla en NULL
      tabla[i]=NULL;
    }
    for(int i=0; i<tam;i++ ){// transfiere los pares antiguos a la nueva tabla 
      struct nodo *it , *next;
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
int MapH_SC_PA::get(string clave) {
  int i=hash(clave);// hace el hash  del string para saber donde comenzar la busqueda
  if(tabla[i] != NULL){// si hay una lista asociada a la posicion i
    struct nodo *it =tabla[i];
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
int MapH_SC_PA::remove(string clave) {
  int i=hash(clave);
  if(tabla[i] !=NULL){// si hay nodos insertados en la pasicion i , se revisa si está la clave a elimiar
    struct nodo *it=tabla[i];// puntero que recorre la lista
    struct nodo *prev;// guarda el nodo anterior
    struct nodo *head;// guuarda el primer nodo asociado a la posicion i 
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
        n--;
        delete(it);
        return val;
       }
       else{
         struct nodo * aux;
         val=it->kv.second;
         aux=it->next;
         prev->next=aux;
         n--;
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
int MapH_SC_PA::removeRH(string clave) {
   remove(clave);// retira la clave
  if(0.5>(double)n/m){// mira si el factor de carga es menor a 0.5 si es así realiza rehashing 
  
   int tam = m;// guarda el tamaño de la tabla antigua 
    m=m/2; // reduce el tamaño a la mitad
    struct nodo** t_aux = tabla;// la tabla actual es respaldada
    tabla = new struct nodo* [m];// crea una nueva tabla con tamaño m/2 
    n=0;
   for (int i=0;i<m; i++ ){// inicializa una tabla en NULL
      tabla[i]=NULL;
    }
    for(int i=0; i<tam;i++ ){// hace rehashing de todos los pares insertados en la tabla 
      struct nodo *it , *next;
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
  
