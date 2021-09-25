#include<bits/stdc++.h>
using namespace std;

void removeduplicates(char s[]){
    if(s[0] == '\0')
        return;
    
    if(s[0] == s[1]){
        int i=1;
        for(;s[i] != '\0';i++){
            s[i-1] = s[i];
        }
        s[i-1] = s[i];
        removeduplicates(s);
    }
    removeduplicates(s+1);
}



int main(){
    
    // write your code here
    int t; 
    cin>>t;
    while(t--){
        char str[10000];
        cin>>str;
        removeduplicates(str);
        cout<<str<<endl;
    }
    return 0;
}