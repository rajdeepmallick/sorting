/*This is a function problem.You only need to complete the function given below*/
/* The task is to complete select() which is used 
   as shown below to implement selectionSort() */
/* A function to implement selection sort
void selectionSort(int arr[], int n)
{
   int i, j;
   for (i = n-1; i >=0; i--)      
   {
        int j = select(arr, i);
        swap(&arr[i], &arr[j]);
   }
}
 */
 
 
 
//my code 
int select(int arr[], int i){
    int maxIndex=i;
    for(int j=0;j<i;j++){
        if(arr[j]>arr[maxIndex])
            maxIndex=j;
    }
    return maxIndex;
}
