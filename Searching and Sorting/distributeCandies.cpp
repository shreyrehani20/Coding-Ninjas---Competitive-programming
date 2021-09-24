#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(int *arr, int n, int k, int mid){

    int sum = 0;
    for(int i=0;i<n;i++){
        sum += (arr[i]/mid);
        if(sum >= k){
            return true;
        }
    }
    return false;
}



int main(){
    // write your code
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int *arr = new int [n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        sort(arr,arr+n);
        int start = 0;
        int end = arr[n-1];
        int ans = -1;
        
        while(start<=end){
            int mid = (start+end)/2;
            
            if(check(arr, n, k, mid)){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}