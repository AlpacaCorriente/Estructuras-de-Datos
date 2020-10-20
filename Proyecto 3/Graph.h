#ifndef GRAFO 
#define GRAFO
#include <bits/stdc++.h>
#include "GraphADT.h"

 using namespace std;

class Graph: GraphADT{
private:
	int aristas;
	int vertices;
	vector < int > visitado;
	vector<vector<int > > adjList;
	void bfs(int);
	pair<int,int> dfs(int , set<int>& );
	void reiniciarvisitado();
	void recorrerGrafo(int nodo , stack<int>*);
	vector<vector <int > > transponerGrafo(vector<vector<int > > , int);
public:
	Graph(int);
	~Graph();
	int  size();  // retorna la cantidad de nodos
	int edges(); //   retorna la cantidad de aristas
	void addEdge(int,int) ;//agrega arista desde el primer nodo(n) al segundo(v) 
	pair<int,int> WCC(); //   retorna par (n° nodos en WCC, n° aristas en WCC)
	pair<int,int> SCC(); //   retorna par (n° nodos en SCC, n° aristas en SCC)
    int transitiveClosure();  
    
};
#endif