#include <bits/stdc++.h>
#include "Queue.h"

Queue::Queue(){

}

Queue::~Queue(){
	while(!_st1.empty())
      _st1.pop();

}

bool Queue::empty(){
	_st1.empty();
}

int Queue::size(){
	_st1.size();
}

int Queue::front(){
	int b;
	while(!_st1.empty()){
		_st2.push(_st1.top());
		_st1.pop();
	}
	b=_st2.top();
	while(!_st2.empty()){
		_st1.push(_st2.top());
		_st2.pop();
	}
	return b;
}

int Queue::back(){
	return _st1.top();
}

void Queue::push(int n){
	
	_st1.push(n);

}
void Queue::pop(){
	while(!_st1.empty()){
		_st2.push(_st1.top());
		_st1.pop();
	}
	_st2.pop();
	while(!_st1.empty()){
		_st1.push(_st2.top());
		_st2.pop();
	}

}
