#include <bits/stdc++.h> 
using namespace std;
void Max_heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    if (l < n && arr[l] > arr[largest]) 
        largest = l;
    if (r < n && arr[r] > arr[largest]) 
        largest = r;
    if (largest != i) { 
        swap(arr[i], arr[largest]); 
        Max_heapify(arr, n, largest);
    } 
}
void heapSort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--) 
        Max_heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); Max_heapify(arr, i, 0);
    } 
}
void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n";
}
int main()
{
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
    printArray(arr,ni);
    clock_t time_req; time_req = clock(); 
    heapSort(arr, ni);
    time_req = clock() - time_req;
    cout <<"Sorted array is \n";
    printArray(arr, ni);
    cout << "Elapsed Time " <<fixed<<(float)time_req/CLOCKS_PER_SEC <<setprecision(5)<<" seconds " <<endl;
    return 0;
}
