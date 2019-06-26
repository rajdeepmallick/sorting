//insertionSort for an array

#include<bits/stdc++.h>
using namespace std;

void printArray(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int *a,int n){
    int key,j;
    for(int i=1;i<n;i++){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void insertionsort(int *a,int n){
    int key,j;
    for(int i=1;i<n;i++){
        key=a[i];
        j=i;
        while(j>0 && a[j-1]>key){
            a[j]=a[j-1];
            j--;
        }
        a[j]=key;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }    
    insertionSort(a,n);  
    printArray(a,n);
    insertionsort(b,n);  
    printArray(b,n);
}
