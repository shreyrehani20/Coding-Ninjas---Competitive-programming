#include<bits/stdc++.h>
using namespace std;

int solve(){
    
    int n, chairs=0; cin>>n;
    int* arr = new int[n];
    int* dep = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>dep[i];
    }
    sort(arr,arr+n);
    sort(dep,dep+n);
    for(int i=0,j=0;i<n;i++){
        if(arr[i]<dep[j]){
            chairs++;
            continue;
        }
        j++;
    }
    return chairs;
}


int main() {

	// Write your code here 
    cout<<solve();
    return 0;
}