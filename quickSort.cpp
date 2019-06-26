//quicksort for array

#include<bits/stdc++.h>
using namespace std;

void printArray(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int partition(int *a,int s,int e){
    int pivot=a[e];
    int pIndex=s;
    
    for(int i=s;i<=e-1;i++){
        if(a[i]<=pivot){
            swap(a[i],a[pIndex]);
            pIndex++;
        }
    }
    swap(a[e],a[pIndex]);
    return pIndex;
}

void quickSort(int *a,int s,int e){
    if(s>=e)
        return;
    int p=partition(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    quickSort(a,0,n-1);  
    printArray(a,n);
}
