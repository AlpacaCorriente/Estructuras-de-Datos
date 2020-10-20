#include <bits/stdc++.h>
#include "Suffix_array.h"
using namespace std;


int comp(pair< int,char*> S1 , pair<int,char*> S2){
   return( strcmp(S1.second ,S2.second));
}

  suffix_array::suffix_array( char * text , int n ){

    vector<pair<int ,char*>>  suffix (1000);
    cout<<"sufic";


    for(int i = 0  ; i < n ; i ++  ){

      suffix[i].first = i;
      suffix[i].second= (text+i);
      cout<<(text+i);
 }
     sort(suffix.begin(),suffix.end(),comp);
   cout<<"sufic";
  for(int i= 0 ; i<n; i++){
    index_suffix.push_back(suffix[i].first); 
    cout<<suffix[i].second<<endl;
   }

  }

  suffix_array::~suffix_array(){

  }

  //hacer busquedas binarias 
  void suffix_array::search(char*){
   /* int inf = 0; //cota inferior 
    int  sup=tam;// cota superior
    int mid=0;

   while ((inf+1 )!= sup){
    mid=(inf+sup)/2;
      if(vec[mid]==num){
        return vec[mid];
      }

    if(vec[mid]<num){
        inf = mid;
        mid=(inf+sup)/2;
      }
    if(vec[mid]>num){
        sup =mid;
        mid=(inf+sup)/2;
      }
  
    }
   return -1;*/
  }
