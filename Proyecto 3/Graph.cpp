#include <bits/stdc++.h>
#include "Graph.h"

using namespace std;

Graph :: Graph (int n){// crea el grafo con la capacidad de n vertices 
vertices=n;
adjList.resize(n); 
visitado.resize(n);
for(int i=0; i<vertices ; i++ ) {
	visitado[i]=0;}
	cout<<"grafo constructor"<<endl;
	aristas=0;
}
Graph :: ~Graph(){

}
void Graph :: addEdge (int n , int v){

	adjList[n].push_back(v);
	cout<< n << "  "<<v<<endl;
	aristas++;

}
 int Graph :: size(){
 	return vertices;


}
int  Graph::edges(){
return aristas;
}

pair<int,int> Graph:: WCC(){	



 } 
pair<int,int> Graph::SCC(){//Componente fuertemente conectada

cout<<"SCC"<<endl;
stack<int> *rec = new stack<int>; 
for(int i=0; i<vertices; i++){
	if(visitado[i]==0){
		recorrerGrafo(i,rec);
	}
}
vector<vector<int > > gTranspuesto=transponerGrafo (adjList,vertices);
vector<vector<int > > aux=adjList;
adjList=gTranspuesto;

 reiniciarvisitado();
  
  while(!rec->empty()){
 	int vertice= rec->top();
 	rec->pop();
 	if(visitado[vertice]==0){
 		set<int> m;
 		pair <int,int> t= dfs(vertice, m);
 		cout<<t.first<< " "<<t.second << endl;
 

 	}
 }


} 

 int Graph::transitiveClosure(){

 } 
 void Graph :: bfs(int nodo){
 	queue<int> q;
 	q.push(nodo);
 	while(!q.empty()){
 		int actual = q.front();
 		q.pop();
 		for(int i=0 ; i<adjList[actual].size();i++){
 			int next=adjList[actual][i];
 			if(visitado[next]==0){
 		//		cout<<"visitado"<<next<<endl;
 				visitado[next]=1;
 				q.push(next);
 			}

 		}
 	}
 }
pair <int , int> Graph :: dfs(int nodo , set<int> &s ){ //set guarda los vertices de la componente conexa
	pair<int , int > pa; // falta insertar caso base (1,0); primer nodo, 0 arista
	pa=make_pair(1,0);
	s.insert(nodo);
 	//if(visitado[nodo]) return;
	visitado[nodo]=1;
	 //cout<<nodo  <<endl;
	for(int i=0; i<adjList[nodo].size();i++){
		int hijo =adjList[nodo][i];
		if(!visitado[hijo]){ 
			pair<int , int >p;
			p=dfs(hijo, s);
			pa = make_pair(p.first+pa.first , p.second +pa .second+ 1);
		//	cout<<"visitado:" << hijo<<endl;

		}else{
			//cout<<"ya fue visitado::"<< hijo<< endl;
			if(s.find(hijo)!= s.end() ){
			pa = make_pair(pa.first , pa.second + 1);
		//	cout<< "visitado pero esta"<<hijo << endl;
			}

		}
	}
	return pa;
}

 void Graph:: recorrerGrafo(int nodo , stack<int> *pila){
 	if(visitado[nodo]) return;
	visitado[nodo]=1;
	for(int i=0; i<adjList[nodo].size();i++){
		int hijo =adjList[nodo][i];
		if(!visitado[hijo]){
			//cout<<"visitando hijo"<<hijo<<endl;
			recorrerGrafo (hijo , pila);
		}
	}
	pila->push(nodo);
 }
vector<vector<int > > Graph::transponerGrafo (vector<vector<int > > grafo , int tam){
vector<vector<int > > grafoT;
	grafoT.resize(tam);
	for(int i = 0 ; i< tam; i++){
		for(int j=0; j<grafo[i].size(); j++){
			grafoT[grafo[i][j]].push_back(i);
  		}
  	}
  	return grafoT;
 }
 void Graph:: reiniciarvisitado(){
	for(int i=0; i<vertices ; i++ ) {
		visitado[i]=0;}
}