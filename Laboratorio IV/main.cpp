#include <bits/stdc++.h>
#include "SparceTable.h"
#include "SegmentTree.h"

using namespace std;

int main () {
  vector<int> NUMS;
    int cant;
     cin>>cant;

    srand(time(NULL));
    
    for(int i= 0 ; i<cant;++i) NUMS.push_back(rand()%(2*cant));
   
    SegmentTree *ST1= new SegmentTree( NUMS);
    cout<<"terminó"<<endl;
    SparceTable *ST2 =new SparceTable(cant ,NUMS);
  

    return 0;
}
