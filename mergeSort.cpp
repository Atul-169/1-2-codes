#include <iostream>
#include<cstdlib>
#include<ctime>
#define N 100000
using namespace std;
void merge(int arr[],int low,int mid,int high){
    int* merged=new int [high-low];
    int left=low,right=mid,k=0;
    while(left<mid && right<high){
        if(arr[left]<arr[right]){
            merged[k++]=arr[left++];
        }
        else{
            merged[k++]=arr[right++];
        }
    }
    while(left<mid){
        merged[k++]=arr[left++];
    }
    while(right<high){
        merged[k++]=arr[right++];
    }
    for(int i=0;i<high-low;i++){
        arr[low+i]=merged[i];
    }
    delete []merged;


}
void mergeSort(int* arr,int low,int high){
    if(high-low<=1) return;
    int mid=low+(high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid,high); //divide step completed,now we have to merge
    merge(arr,low,mid,high);
    

}
int main(){
    int arr[N];
    srand(time(NULL));
    for(int i=0;i<N;i++){
        arr[i]=rand()%10;
    }
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    mergeSort(arr,0,N);
    cout<<"\n";
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
}