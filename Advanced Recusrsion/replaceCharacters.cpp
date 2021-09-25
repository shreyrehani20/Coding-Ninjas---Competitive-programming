#include<bits/stdc++.h>
using namespace std;

void charreplace(char s[], char c1, char c2){
    if(s[0] == '\0'){
        return;
    }
    
    if(s[0] == c1){
        s[0] = c2;
        charreplace(s+1, c1, c2);
    }
    else
        charreplace(s+1, c1, c2);
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        char str[100];
        char c1,c2;
        cin>>str;
        cin>>c1>>c2;
        charreplace(str, c1, c2);
        cout<<str<<endl;
    }
    return 0;
}