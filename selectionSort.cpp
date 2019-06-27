//selection sort for array

#include<bits/stdc++.h>
using namespace std;

void printArray(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int *a,int n){
    int imin,min;
    for(int i=0;i<n-1;i++){
    	imin=i;
        for(int j=i+1;j<n;j++){
            if(a[imin]>a[j])
                imin=j;
        }
        //min=a[imin];
        // int t=a[imin];
        // a[imin]=a[i];
        // a[i]=t;
        swap(a[i],a[imin]);
        /*
        void swap(int *a,int *b){
            int t=*a;
            *a=*b;
            *b=t;
        }
        so swap(a[i],min) will not work
        */
    }
    //printArray(a,n);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    selectionSort(a,n);
    printArray(a,n);
    return 0;
}
