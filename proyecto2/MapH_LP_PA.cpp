#include <bits/stdc++.h>
#include "MapH_LP_PA.h"

using namespace std;


// **prueba lineal con Polinomial**

//inicia un mapa vacio
MapH_LP_PA::MapH_LP_PA(int cant) {
    n = 0; 
     m=cant/0.5;// calcula el tamaño de la tabla respecto al factor de carga 
    tabla=  new pair<string,int>* [m];
    for (int i=0;i<m; i++ ){// inicializa una en NULL
      tabla[i]=NULL;
    }

  }
MapH_LP_PA::~MapH_LP_PA(){
      for (int i=0;i<m; i++ ){
       delete (tabla[i]);
    }
    delete(tabla);
   }
int MapH_LP_PA::size(void) {
return n;
}
bool MapH_LP_PA::isEmpty(void) {// retorna si está vacio
return size() == 0;
}


int MapH_LP_PA::hash(string clave){
  int h=0;
  for (int i = 0; i<clave.length(); ++i)
  {
    h=(31*h + (int)clave[i])%m;
  }
  return h;
  }
/* inserta el par clave-valor en el arreglo , 
recorre el arreglo circular hasta que encuentra una posicion valida(vacia / disponible) para insertar*/
void MapH_LP_PA::put(pair<string , int> v) {
	//if (n >= m/2) resize(2*m); // tamaño de la tabla doble si esta lleno
	int i = hash(v.first);
  int aux =i-1;
  if(get(v.first) == -1){// si el elemento no está previamente insertado , comieza la insercion 
   while(i != aux) {
        if (tabla[i]==NULL) {//  realiza la insercion si la posicion está vacia
          tabla[i] = new pair<string,int>;
          tabla[i]->first=v.first;
          tabla[i]->second=v.second;
          n++;
          break;
        }
        if(tabla[i]->first =="DISPONIBLE"){//  realiza la insercion si la posicion está llena
          tabla[i]->first= v.first;
          tabla[i]->second= v.second;
          break;
        }
        i=(i+ 1)% m;
		}
  }
 }


/*obtiene el valor asiciado de una clave ya insertada*/
int MapH_LP_PA::get(string clave) {
  int i=hash(clave);// hace el hash  del string para saber donde comenzar la busqueda
  int aux=i-1;
 while(tabla[i] != NULL){
   if (clave.compare(tabla[i]->first) == 0) {
     return tabla[i]->second;
		}
    if(aux==i){// si se da una vuelta completa en el arreglo circular y no está  el string , retorna -1 
      return -1;
    }

     i = (i + 1) % m;
    }
  return -1;
}
/* es eliminda del registro  la clave junto al valor asociado */
int MapH_LP_PA::remove(string clave) {
  int i=hash(clave);
  int aux=i-1;
  while(tabla[i] != NULL){
    if(clave.compare(tabla[i]->first)==0){// si encuentra la clave se elimina  y remplaza al par por clave DISPONIBLE y valor -1  
      int aux;
      aux=tabla[i]->second;
      tabla[i]->first="DISPONIBLE";
      tabla[i]->second=-1;
      return aux; // se retorna el valor asociado al string eliminado 
    }
    i=(i+1)%m;
    if(aux==i){
      return -1;// se retorna el valor asociado al string eliminado 
    }
  }
  return -1;
}
