#include <bits/stdc++.h>
#include <unistd.h>
#include "LinkedList.h"
#include "skipList.h"
using namespace std;
int main(){
	int f;
	cin>>f;
	MiniSet *sm = new LinkedList();

	MiniSet *mn = new SkipList();
	vector<int> myvector;
	for (int i=0; i<f; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

  // using built-in random generator:
  random_shuffle ( myvector.begin(),myvector.end() );

  cout << "myvector contains:";
  ;
  for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it){
  	   sm->insert(*it);}
       double tiempo=(double)(clock()-start)/CLOCKS_PER_SEC;
       cout<<endl<<"Tiempo de insercion Lista:"<<tiempo<< endl;  

       start= clock();
       for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it){
  	   mn->insert(*it);}
        tiempo=(double)(clock()-start)/CLOCKS_PER_SEC;
       cout<<"Tiempo de insercion skipList:"<<tiempo<< endl;  

	random_shuffle ( myvector.begin(), myvector.end() );
	 start= clock();
	for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it){
  	   sm->remove(*it);
  	}
  	tiempo=(double)(clock()-start)/CLOCKS_PER_SEC;
       cout<<"Tiempo de borrado Lista:"<<tiempo<< endl;  

	cout << '\n';
	start= clock();
   for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it){
  	   mn->remove(*it);
  	}
  	tiempo=(double)(clock()-start)/CLOCKS_PER_SEC;
  	cout<<"Tiempo de borrado skipList:"<<tiempo<< endl;
random_shuffle ( myvector.begin(), myvector.end() );
    start= clock();
   for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it){
       sm->search(*it);
    }
    tiempo=(double)(clock()-start)/CLOCKS_PER_SEC;
     cout<<"Tiempo de busqueda Lista:"<<tiempo<< endl;
        start= clock();
   for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it){
       mn->remove(*it);
    }
    tiempo=(double)(clock()-start)/CLOCKS_PER_SEC;

    cout<<"Tiempo de busqueda skipList:"<<tiempo<< endl;
	delete(sm);
	delete(mn);
	return 0;

}