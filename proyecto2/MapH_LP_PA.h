#ifndef MapHLPPA_H
#define MapHLPPA_H

#include "MapADT.h"

class MapH_LP_PA : MapADT {
private:
        int n;           //número de pares clave-valor en la tabla de símbolos             
        int m;           //tamaño de la tabla de prueba lineal           
        pair<string , int>** tabla; //Par clave-valor
        int hash(string);
public:
      MapH_LP_PA(int);
      ~MapH_LP_PA();
        bool isEmpty(void);
        int size(void);
        void put(pair<string, int>);
        int get(string);
        int remove(string); 
};   
#endif
