#include<bits/stdc++.h>
using namespace std;

int dp[505][505];
int magicGrid(int ** hm, int si, int sj, int r, int c){
    
    if(si == r && sj == c)
        return 1;
    
    // if(si == r-1 || sj == c-1)
    //     return 1;
    
    if(si>r || sj>c)
        return INT_MAX;
    if(dp[si][sj]!=-1)return dp[si][sj];
    int option1 = magicGrid(hm, si+1, sj, r, c);
    int option2 = magicGrid(hm, si, sj+1, r, c);
    return dp[si][sj] = max(min(option1,option2)-hm[si][sj],1);
    // return min(option1, option2);
}



int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int r,c;
        cin>>r>>c;
        memset(dp,-1,sizeof(dp));
        int ** hm = new int*[r+1];
        for(int i=1;i<=r;i++)
            hm[i] = new int[c+1];
        
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++)
                cin>>hm[i][j];
        }
        
        cout<<magicGrid(hm, 1, 1, r, c)<<endl;
        
        
    }
    return 0;
}