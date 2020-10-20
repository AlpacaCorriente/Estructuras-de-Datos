#ifndef MAPHLPB_H
#define MAPHLPB_H
#include <utility>
#include <string>
#include "MapADT.h"

class MapH_LP_B: MapADT {
private:
        int n;           //número de pares clave-valor en la tabla de símbolos             
        int m;           //tamaño de la tabla de prueba lineal           
        pair<string , int>** tabla; //Par clave-valor
        int hash(string);
public:
        MapH_LP_B(int);
        ~MapH_LP_B();
        bool isEmpty(void);
        int size(void);
        void put(pair<string, int>);
        int get(string);
        int remove(string);
};   
#endif
