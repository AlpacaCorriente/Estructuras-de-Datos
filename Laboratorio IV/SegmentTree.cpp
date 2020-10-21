#include <bits/stdc++.h>
#include "SegmentTree.h"

using namespace std;


SegmentTree:: SegmentTree(vector< int > &_A){
A= _A ;
n= (int)A.size();
st.assign(4*n , 0 );// tamaño del segment tree
build ( 1,0,n-1);

}

int SegmentTree:: left(int p){ return p<< 1 ;} // operaciones del binary heap
int SegmentTree:: right (int p){  return (p<< 1)+ 1; }

void SegmentTree:: build (int p , int L , int R ){
    
    if(  R==L ){
        st[p]=L;

    }else{
        build(left(p), L , (L+R)/2);
        build ( right(p), (L+R)/2,R);
        int p1 = st[left (p)], p2 = st[right(p)];
        st[p]= (A[p1]<= A[p2]) ? p1:p2;
    }
}

int SegmentTree:: rmq(int p , int L, int R , int i , int j ){
    if ( i>R || j<L ) return -1 ;
    if( L  >= i && R<= j ) return st[p];

    int p1 = rmq(left(p) , L , (L+R) / 2, i, j);
    int p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);

    if (p1== -1 ) return p2;
    if (p2 == -1)return p1 ;

    return (A[p1]<= A[p2])? p1: p2;

}
int SegmentTree ::  RMQ(int i , int j ){
     return rmq(1,0,n-1 , i, j);
}



