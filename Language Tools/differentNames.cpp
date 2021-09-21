#include <bits/stdc++.h>
using namespace std;

void solve(){
 
    int count=0, sum=0;
    string names;
    getline(cin,names);
    string temp;
    
    unordered_map<string, int> freq;
    
    for(int i=0;i<names.length();i++){
        if(names[i] == ' '){
            freq[temp]++;
            temp = "";
            count++;
        }
        else{
            temp += names[i];
        }
    }
    freq[temp]++; 
    count++;
    unordered_map<string,int>::iterator it;
    for(it = freq.begin();it!=freq.end();it++){
        if(it->second>=2){
            cout<<it->first<<" "<<it->second<<endl;
        }
        if(it->second == 1){
            sum++;
        }
    }
    
    if(sum == count)
        cout<<"-1";
    
}



int main() {
    // Write your code here
    solve();
    return 0;
}