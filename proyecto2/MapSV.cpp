#include <bits/stdc++.h>
#include "MapSV.h"

using namespace std;
MapSV::MapSV(int n) {

   //vec=new vector<string>;
    tam=0;

  }
  MapSV::~MapSV(){

  }
int MapSV::size(void) {// retorna el tamaño de carga 
return tam;
}
bool MapSV::isEmpty(void) {// retorna si está vacio
return size() == 0;
}

void MapSV::put(pair<string,int> k ) {//inserta un string ordenado al vector vec
  if(get(k.first)== -1){// si no existe anteriormente comienza la insercion 
      vec.push_back(k);
    }
  sort(vec.begin() , vec.end() );
}
 

/*Elimina la clave especificada y su valor asociado de esta tabla de símbolos
 */
 int MapSV::get(string clave) {
  int inf = 0;
  int mid; //cota inferior 
   int  sup=tam;// cota superior
if(tam!=0){// comienza la busqueda binaria sobre el vector 
   while ( (inf+1 )!= sup){
    mid=(inf+sup)/2;
      if(vec[mid].first==clave){
        return mid;
      }

    if(vec[mid].first>clave){
        sup =mid;
        mid=(inf+sup)/2;
      }

    if(vec[mid].first<clave){
        inf = mid;
        mid=(inf+sup)/2;
      }
    }
  }
   return -1;
}

//Devuelve el valor asociado con la clave especificada e elimina la clave
int MapSV::remove(string clave) {
  int k ;
  k=get(clave);
if (k !=-1){// si la clave está se elimina del vector 

 vec.erase(vec.begin()+k);
 tam--;
}
} 
  

 
