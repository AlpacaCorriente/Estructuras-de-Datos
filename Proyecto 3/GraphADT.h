#ifndef  GF_A
#define GF_A

using namespace std;

class GraphADT{

public:
	virtual int  size() =0;  // retorna la cantidad de nodos
	virtual int edges() =0; //   retorna la cantidad de aristas
	virtual void addEdge( int ,int)=0;  //agrega arista desde el primer nodo al segundo 
	virtual pair <int,int> WCC()=0;   //   retorna par (n° nodos en WCC, n° aristas en WCC)
	virtual pair <int,int> SCC()=0;    //   retorna par (n° nodos en SCC, n° aristas en SCC)
	virtual int transitiveClosure() =0;  // retorna cantidad promedio de nodos alcanzables promedio
};
#endif