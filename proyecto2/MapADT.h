#ifndef MAPADT_H
#define MAPADT_H


#include <utility>
#include <string>

using namespace std;

class MapADT{
	public:
      virtual bool isEmpty(void)		 = 0; // Verificar si está vacío
      virtual int size(void)			 = 0;  //Obtener el tamaño
      virtual void put(pair<string, int>)= 0; //Insertar un valor que tiene asociado una llave 
      virtual int  get (string) 		     = 0;//encontrar el valor que tiene asociado a una llave
      virtual int  remove(string)		 = 0;//Eliminar el valor asociado a una llave
};   

#endif
