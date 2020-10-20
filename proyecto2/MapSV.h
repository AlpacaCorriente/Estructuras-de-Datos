#ifndef MAPSV
#define MAPSV

#include <utility>
#include <string>
#include "MapADT.h"
using namespace std;

class MapSV: MapADT{
private:
        int tam;                    
        vector < pair<string,int> > vec;
public:
        MapSV(int );
        ~MapSV();
        bool isEmpty(void);
        int size(void);
        void put(pair<string, int>);
        int get(string);
        int remove(string);
};   
#endif
