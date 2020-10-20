#include <bits/stdc++.h>
#include <unistd.h>

#include "MapH_LP_B.h"
#include "MapH_LP_PA.h"
#include "MapH_SC_B.h"
#include "MapH_SC_PA.h"
#include "MapSV.h"
using namespace std;

string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    string str(length,0);
    generate_n( str.begin(), length, randchar );
    return str;
}

int main(void) {
int tam;
	cin>>tam;
   MapSV *map = new MapSV(0);
   MapH_SC_B *mscb= new MapH_SC_B(tam);
   MapH_SC_PA *mscpa= new MapH_SC_PA(tam);
   MapH_LP_PA *mlppa= new MapH_LP_PA(tam);
   MapH_LP_B *mlpb =new MapH_LP_B(tam);
   clock_t start, stop;
   vector<string> p;
   srand(time(NULL));
   for (int i = 0; i < tam; ++i)
   {string pal =random_string(rand()%25);
    p.push_back(pal);
   }


    start=clock_t();
for(int i =0;i<tam;i++){
    mscb->put(make_pair(p[i],i));
}
stop=clock();
cout<<"put encadenamiento separado-caracter"<<(double)(stop-start)/CLOCKS_PER_SEC/tam << endl;

 start=clock_t();
for(int i =0;i<tam;i++){
    mscpa->put(make_pair(p[i],i));
}
stop=clock();
cout<<"put encadenamiento separado-polinomial "<<(double)(stop-start)/CLOCKS_PER_SEC/tam<< endl;

 start=clock_t();
for(int i =0;i<tam;i++){
    mscb->get(p[i]);
}
stop=clock();
cout<<"get encadenamiento separado-primer caracter"<<(double)(stop-start)/CLOCKS_PER_SEC/tam << endl;
 start=clock_t();
for(int i =0;i<tam;i++){
    mscpa->get(p[i]);
}
stop=clock();
cout<<"get  encadenamiento separado-polinomial "<<(double)(stop-start)/CLOCKS_PER_SEC/tam<< endl;


   /*inserciones 
 start=clock_t();
for(int i =0;i<tam;i++){
    mscb->put(make_pair(p[i],i));
}
stop=clock();
cout<<"put encadenamiento separado-caracter"<<(double)(stop-start)/CLOCKS_PER_SEC/tam << endl;

 start=clock_t();
for(int i =0;i<tam;i++){
    mscpa->put(make_pair(p[i],i));
}
stop=clock();
cout<<"put encadenamiento separado-polinomial "<<(double)(stop-start)/CLOCKS_PER_SEC/tam<< endl;

 start=clock_t();
for(int i =0;i<tam;i++){
    mlpb->put(make_pair(p[i],i));
}
stop=clock();
cout<<"put prueba lineal -primer caracter "<<(double)(stop-start)/CLOCKS_PER_SEC/tam << endl;


 start=clock_t();
for(int i =0;i<tam;i++){
    mlppa->put(make_pair(p[i],i));
}
stop=clock();
cout<<"put prueba lineal -polinomial "<<(double)(stop-start)/CLOCKS_PER_SEC/tam << endl;
 start=clock_t();

for(int i =0;i<tam;i++){
    map->put(make_pair(p[i],i));
}
stop=clock();
cout<<"put MapSV  "<<(double)(stop-start)/CLOCKS_PER_SEC/tam << endl;

random_shuffle(p.begin(),p.end());
/*get
 start=clock_t();
for(int i =0;i<tam;i++){
    mscb->get(p[i]);
}
stop=clock();
cout<<"get encadenamiento separado-primer caracter"<<(double)(stop-start)/CLOCKS_PER_SEC/tam << endl;
 start=clock_t();
for(int i =0;i<tam;i++){
    mscpa->get(p[i]);
}
stop=clock();
cout<<"get  encadenamiento separado-polinomial "<<(double)(stop-start)/CLOCKS_PER_SEC/tam<< endl;

 start=clock_t();
for(int i =0;i<tam;i++){
    mlpb->get(p[i]);
}
cout<<"get  prueba lineal - Primer caracter "<<(double)(stop-start)/CLOCKS_PER_SEC/tam<< endl;

 start=clock_t();
for(int i =0;i<tam;i++){
    mlppa->get(p[i]);
}

cout<<"get  prueba lneal - polinomial "<<(double)(stop-start)/CLOCKS_PER_SEC/tam<< endl;
 start=clock_t();
for(int i =0;i<tam;i++){
    map->get(p[i]);
}
cout<<"MapSV "<<(double)(stop-start)/CLOCKS_PER_SEC/tam<< endl;


/*remove
 start=clock_t();
for(int i =0;i<tam;i++){
    mscb->remove(p[i]);
}
stop=clock();
cout<<"remove encadenamiento separado-caracter"<<(double)(stop-start)/CLOCKS_PER_SEC/tam << endl;

 start=clock_t();
for(int i =0;i<tam;i++){
    mscpa->remove(p[i]);
}
stop=clock();
cout<<"remove encadenamiento separado-polinomial "<<(double)(stop-start)/CLOCKS_PER_SEC/tam<< endl;

start=clock_t();
for(int i =0;i<tam;i++){
    mlpb->remove(p[i]);
}
stop=clock();
cout<<"remove prueba lineal-primer caracter "<<(double)(stop-start)/CLOCKS_PER_SEC/tam << endl;

 start=clock_t();
for(int i =0;i<tam;i++){
    mlppa->remove(p[i]);
}
stop=clock();
cout<<"remove prueba lineal-polinomial "<<(double)(stop-start)/CLOCKS_PER_SEC/tam << endl;

 start=clock_t();
for(int i =0;i<tam;i++){
    map->remove(p[i]);
}
stop=clock();
cout<<"remove MapSV"<<(double)(stop-start)/CLOCKS_PER_SEC/tam << endl;*/



    
    return 0;    
}