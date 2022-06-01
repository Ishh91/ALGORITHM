#include<iostream>
using namespace std;
void countSort(int arr[],int size){
    int out[10],cnt[10];
    int max = arr[0];
    for(int i = 0; i<=max; i++){
        cnt[i] = 0;
    }
    for(int i = 0;i<size; i++){
        cnt[arr[i]]++;
    }
    for(int i = 0;i<=max;i++)
    {
        cnt[i] += cnt[i-1]; 
    }
    for(int i =size - 1; i>=0; i++){
        out[cnt[arr[i]] - 1] =arr[i];
        cnt[arr[i]]--;
    }
    for(int i = 0;i<size;i++){
        arr[i] = cnt[i];
    }

}
void printArray(int arr[], int size){
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}

int main(){
    int array[] = {4, 2, 2, 8, 3, 3, 1};
    int size = sizeof(array)/ sizeof(array[0]);
    countSort(array,size);
    printArray(array,size);
}