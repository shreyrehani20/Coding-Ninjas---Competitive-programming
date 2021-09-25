#include<bits/stdc++.h>
using namespace std;

void merge(int *arr,int *temp, int left, int mid, int right){
    int i = left;
    int j = mid;
    int k = 0;
    
    while(i<mid && j<=right){
        if(arr[i]<=arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    
    while(i<mid){
        temp[k++] = arr[i++];
    }
    while(j<=right){
        temp[k++] = arr[j++];
    }
    
    for(int i=left,k=0;i<=right;i++,k++){
        arr[i] = temp[k];
    }
    return;
}


void mergeSort(int *arr,int *temp, int left, int right){
    if(right>left){
        int mid = (right+left)/2;
        mergeSort(arr,temp, left, mid);
        mergeSort(arr,temp, mid+1, right);
        merge(arr,temp, left, mid+1, right);
    }
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int size;
        cin>>size;
        int * arr = new int[size];
        int *temp = new int[size];
        for(int i=0;i<size;i++){
            cin>>arr[i];
        }
        mergeSort(arr,temp,0, size-1);
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }  
        cout<<endl;
    }
    return 0;
}