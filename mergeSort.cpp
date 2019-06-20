#include<bits/stdc++.h>
using namespace std;

void print(int *A,int n){
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;    
}

void Merge(int *A,int l,int m,int r){
    int n1=(m-l+1),n2=(r-m);
    int L[n1],R[n2];
    
    for(int i=0;i<n1;i++)
        L[i]=A[l+i];
    for(int i=0;i<n2;i++)
        R[i]=A[m+1+i];
        
    int i=0,j=0,k=l; 
    
    while(i<n1 && j<n2){
        if(L[i]<R[j])
            A[k++]=L[i++];
        else
            A[k++]=R[j++];
    }
    while(i<n1)
        A[k++]=L[i++];
    while(j<n2)
        A[k++]=R[j++];
}

void MergeSort(int *A,int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        MergeSort(A,l,m);
        MergeSort(A,m+1,r);
        Merge(A,l,m,r);
    }
}

void merge(int *A,int *L,int *R,int n1,int n2){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(L[i]<R[j])
            A[k++]=L[i++];
        else
            A[k++]=R[j++];
    }
    while(i<n1)
        A[k++]=L[i++];
    while(j<n2)
        A[k++]=R[j++];
}

void mergeSort(int *A,int n){
    if(n<2)
        return;
    int m=n/2;
    int *L=new int[m];
    int *R=new int[n-m];
    for(int i=0;i<m;i++)
        L[i]=A[i];
        //print(L,m);
    for(int i=m;i<n;i++)
        R[i-m]=A[i];
        //print(R,(n-m));
    mergeSort(L,m);    
    mergeSort(R,n-m);
    merge(A,L,R,m,(n-m));
    delete[] L;
    delete[] R;
}

int main(){
    int A[]={57,-6,1,0,-19,23,33,-37};
    int n=sizeof(A)/sizeof(int);
    //print(A,n);
    MergeSort(A,0,n-1);
    print(A,n);
    
    int a[]={57,-6,1,0,-19,23,33,-37};
    int N=sizeof(a)/sizeof(int);
    //print(a,N);
    mergeSort(a,N);
    print(a,N);
    return 0;
}

/*
-37 -19 -6 0 1 23 33 57 
-37 -19 -6 0 1 23 33 57 
*/
