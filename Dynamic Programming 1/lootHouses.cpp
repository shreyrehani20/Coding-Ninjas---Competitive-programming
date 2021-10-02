#include<bits/stdc++.h>
using namespace std;

int lootHouse(int ei, int *arr, int si, int *dp){
    
    if(si>=ei)
        return 0;
    
    if(dp[si]>0)
        return dp[si];
    
    int option1 = arr[si] + lootHouse(ei, arr, si + 2, dp);
    int option2 = lootHouse(ei, arr, si + 1, dp);
    
    dp[si] = max(option1, option2);
    
    return max(option1, option2);
    
}




int main(){
    
    // write your code here
    
    int n;
    cin>>n;
    int *arr = new int[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int *dp = new int[n+1];
    
    cout<<lootHouse(n, arr, 0, dp);
    
    return 0;
}