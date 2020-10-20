#include <iostream>
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Graph.h"

using namespace std;

int main(){

 	FILE *Grafo=NULL;
 	char nombre[50];
 	char inicio[50];
 	char final[50];
 	char aristas[50];
 	cout<<"ingrese nombre del archivo"<<endl;
 	 cin>>nombre;
	   Grafo=fopen(nombre,"r");
	   while (Grafo==NULL){
	   	puts("archivo no esta");
	   	cin>> nombre;
	   	cout<<nombre;
	   	Grafo=fopen(nombre,"r");
	   }

	   fscanf(Grafo,"%s %s",inicio, aristas);
	   cout<<inicio <<"  "<<aristas<<endl;
	   Graph grafo_1(atoi(inicio));

	   for ( int i=0; i<atoi(aristas); i++){
	   fscanf(Grafo, "%s %s",inicio,final);
	    grafo_1.addEdge(atoi(inicio),atoi(final));
	}
	puts("terminando ciclo ");
	 grafo_1.SCC();



 	return 0; 
 }