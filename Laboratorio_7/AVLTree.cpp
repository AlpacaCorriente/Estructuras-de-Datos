#include <bits/stdc++.h>
#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree(){
	_root=NULL;
	_size=0;
}

AVLTree::~AVLTree(){
	posorder(_root);
}

void AVLTree::insert(int val){	
	node *aux;
	node *aux2;
	aux=_root;
	aux2=aux;
	if(_root==NULL){// si no hay nodos insertados 
		node *n= new node();
		n->left=NULL;
		n->right=NULL;
		n->padre=NULL;
		n->num=val;
		n->altura=1;
		_root=n;
		_size++;
		aux2=n;
		return;
	}
	else {
	    while (aux!=NULL){
	    if(val <= aux->num){
			aux2=aux;
			aux=aux->left;
		}
		else{
			aux2=aux;
			aux=aux->right;}
		}

	    if(val<=aux2->num){
		node *m = new node();
		m->num = val;
		m->padre=aux2;
		m->altura=1;
		m->left=NULL;
		m->right=NULL;
		aux2->left=m;
		_size++;

	    }
	    if(val=>aux2->num){
		node *m = new node();
		m->padre=aux2;
		m->altura=1;
		m->num = val;
		m->left=NULL;
		m->right=NULL;
		aux2->right=m;
		_size++;
	 }
	}
	if(aux2->right =! NULL || aux2->left=!NULL){
		while(){
			
		}

	}
}


node* AVLTree::search(int val){
	node *aux;
	aux=_root;
	if(_root!= NULL){
		while(aux!=NULL){
		 if(val<=aux->num){
		 	if(aux->num==val){//"valor encontrado";
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

int AVLTree::size(){
	return _size;
}
void AVLTree::posorder(node* aux){
if(aux != NULL){
		posorder(aux->left);
		posorder(aux->right);
		free(aux);
	}
}


