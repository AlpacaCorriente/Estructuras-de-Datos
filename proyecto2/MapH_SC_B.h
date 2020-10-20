#ifndef MAPHSC_B
#define MAPHSC_B
#include <utility>
#include <string>
#include "MapADT.h"
struct node{
        pair<string, int> kv;
        node *next=NULL;
};
class MapH_SC_B: MapADT {
private:
        int n;           //número de pares clave-valor en la tabla de símbolos             
        int m;           //tamaño de la tabla de prueba lineal           
        struct node** tabla; //Par clave-valor
        int hash(string);
        void resize(int);
public:
        MapH_SC_B(int );
        ~MapH_SC_B();
        bool isEmpty(void);
        int size(void);
        void put(pair<string, int>);
        void putRH(pair<string, int>); 
        int removeRH(string);
        int get(string);
        int remove(string);

};   
#endif
