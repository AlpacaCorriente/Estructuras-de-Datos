#include <bits/stdc++.h>
#include "SparceTable.h"

using namespace std;


SparceTable:: SparceTable(int n ,vector< int > &_A){

for (int i = 0; i < n; i++) {
    A[i] = _A[i];
    SpT[i][0] = i;
}

for (int j = 1; (1<<j) <= n; j++){ 
    for (int i = 0; i + (1<<j) - 1 < n; i++){ 
    if (A[SpT[i][j-1]] < A[SpT[i+(1<<(j-1))][j-1]]) SpT[i][j] = SpT[i][j-1]; 
    else  SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
        }
    }
}


int SparceTable:: query (int i ,int j ){
    int k = (int)floor(log((double)j-i+1) / log(2.0));
    if (A[SpT[i][k]] <= A[SpT[j-(1<<k)+1][k]]) return SpT[i][k];
    else return SpT[j-(1<<k)+1][k];
}




