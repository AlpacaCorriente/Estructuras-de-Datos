#include <bits/stdc++.h>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree(){
	_root=NULL;
	_size=0;
}

BinarySearchTree::~BinarySearchTree(){
	posorder(_root);
}

void BinarySearchTree::insert(int val){	
	node *aux;
	node *aux2;
	aux=_root;
	aux2=aux;
	if(_root==NULL){
		node *n= new node();
		n->left=NULL;
		n->right=NULL;
		n->num=val;
		_root=n;
		_size++;
	}
	else {
	    while (aux!=NULL && aux2->num!=val){
	    if(val<=aux->num){
			aux2=aux;
			aux=aux->left;
		}
		else{
			aux2=aux;
			aux=aux->right;}
		}

	    if(val<aux2->num){
		node *m = new node();
		m->num = val;
		m->left=NULL;
		m->right=NULL;
		aux2->left=m;
		_size++;
	    }
	    if(val>aux2->num){
		node *m = new node();
		m->num = val;
		m->left=NULL;
		m->right=NULL;
		aux2->right=m;
		_size++;
	}
	}
}


node* BinarySearchTree::search(int val){
	node *aux;
	aux=_root;
	if(_root!= NULL){
		while(aux!=NULL){
		 if(val<=aux->num){
		 	if(aux->num==val){//cout<<"valor encontrado"<< aux->num<<endl;
		 		return aux;}
			aux=aux->left;
		}
		 else{
			aux=aux->right;
		   }
		}

	  }
	  return NULL;


}

int BinarySearchTree::size(){
	return _size;
}
void BinarySearchTree::posorder(node* aux){
if(aux != NULL){
		posorder(aux->left);
		posorder(aux->right);
		free(aux);
	}
}

