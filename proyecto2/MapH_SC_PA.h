 #ifndef MAPHSC_PA
#define MAPHSC_PA
#include <utility>
#include <string>
#include "MapADT.h"
struct nodo{
        pair<string, int> kv;
        nodo *next=NULL;
};
class MapH_SC_PA: MapADT {
private:
        int n;           //número de pares clave-valor en la tabla de símbolos             
        int m;           //tamaño de la tabla de prueba lineal           
        struct nodo** tabla; //Par clave-valor
        int hash(string);
public:
        MapH_SC_PA(int );
        ~MapH_SC_PA();
        bool isEmpty(void);
        int size(void);
        void put(pair<string, int>);
        int get(string);
        void putRH(pair<string, int>); 
        int removeRH(string);
        int remove(string);
};   
#endif
