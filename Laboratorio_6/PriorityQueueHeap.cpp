#include <bits/stdc++.h>
#include "PriorityQueueHeap.h"

using namespace std;

PriorityQueueHeap::PriorityQueueHeap(){
	Q.push_back(INT_MIN);
  
}

PriorityQueueHeap::~PriorityQueueHeap(){
}

bool PriorityQueueHeap::empty(){
}

int PriorityQueueHeap::size(){
	return _size;
}

int PriorityQueueHeap::top(){
	if(_size!=0){
		return Q[1];
	}

}

void PriorityQueueHeap::push(int n){
	Q.push_back(n);
	_size++;
	it=_size;
	int padre;
	if(_size>1){
	  padre = Q[it/2]; 
	  while (Q[it]<=padre){

	  	Q[it/2]=Q[it];
	  	Q[it]=padre;
	  	it=it/2;
	  	padre=Q[it/2];

	}	
  }
 
  for(int i=1; i <= _size ; i++){
	cout<< Q[i];
 }


}

void PriorityQueueHeap::pop(){
	int hijoder=1;
	int hijoizq=1;
	int padre;
	int aux;
	padre = 1;
	if(_size>1){
		Q[1]=Q[_size];
		Q.pop_back();
		_size--;
	 while(hijoder !=0 || hijoizq !=0){
	 	if((padre*2)+1 <= _size){
	 		hijoder = (padre*2)+1;
	 	}else hijoizq = 0;
	 	if((padre*2)<= _size){
	 		hijoizq =padre*2;
	 	}else hijoizq = 0;



	    if(hijoder != 0 && hijoizq !=0){
	 		if(Q[hijoder]>Q[hijoizq]){
	 			if(Q[hijoizq]<Q[padre]){
	 			aux=Q[padre];
	 			Q[padre]=Q[hijoizq];
	 			Q[hijoizq]=aux;
	 			padre=hijoizq;
	 			break;
	 		}else{hijoder = 0; 
	 			hijoizq = 0;}
	 		}
	 		if(Q[hijoder]<Q[hijoizq]){
	 			if(Q[hijoder]<Q[padre]){
	 			aux=Q[padre];
	 			Q[padre]=Q[hijoder];
	 			Q[hijoder]=aux;
	 			padre=hijoder;
	 			break;
	 		}else {hijoder = 0; 
	 			hijoizq = 0;}	 	  
	 	
	        }
	    }

	 	if(hijoder !=0 && hijoizq == 0){
	 		if(Q[hijoder]<Q[padre]){
	 			aux=Q[padre];
	 			Q[padre]=Q[hijoder];
	 			Q[hijoder]=aux;
	 		    padre=hijoder;
	 		}else hijoder=0;
	 	}

	 	if(hijoizq !=0 && hijoder == 0){
	 		if(Q[hijoizq]<Q[padre]){
	 			aux=Q[padre];
	 			Q[padre]=Q[hijoizq];
	 			Q[hijoizq]=aux;
	 			padre=hijoizq;
	 		}else hijoizq=0;
	 }
	}
	}
   for(int i = 1; i<=_size; i++){
	cout<< Q[i];
     }

}
