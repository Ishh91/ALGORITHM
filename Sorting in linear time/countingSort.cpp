#include <bits/stdc++.h>  
  
using namespace std;  
  
int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }return max;   
} 
void countSort(int a[], int n)
{  
   int output[n+1];  
   int max = getMax(a, n);  
   int count[max+1]; 
  for (int i = 0; i <= max; ++i)   
  {  
    count[i] = 0;  
  }  
  for (int i = 0; i < n; i++)  
  {  
    count[a[i]]++;  
  }  
   for(int i = 1; i<=max; i++)   
     count[i] += count[i-1];   
  for (int i = n - 1; i >= 0; i--) {  
    output[count[a[i]] - 1] = a[i];  
    count[a[i]]--; 
}   
   for(int i = 0; i<n; i++) {  
      a[i] = output[i];  
   }  
}  
void printArr(int a[], int n)
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout<<a[i]<<" ";  
}  
int main() {  
    clock_t start;
    int ni;
    cout<<"Enter the Size of the array:"<<endl; 
    cin>>ni;
    int m,n;
    cout<<"Enter the range of the random function: "<<endl; 
    cin>>n>>m;
    int arr[ni]; 
    srand(time(NULL)); 
    for(int i=0;i<ni;i++){
        arr[i]=rand()%(m-n+1)+n;
    }
    cout<<"array before sorting:"<<endl; 
    printArr(arr,ni);
    start=clock()-start;
    countSort(arr, ni);
    double time_consumed=((double)start)/CLOCKS_PER_SEC;
    cout <<"Sorted array is \n"<<endl;
    printArr(arr, ni);
    cout<<"The time for the event was: "<<time_consumed<<" Second"<<endl;
    return 0;
}  