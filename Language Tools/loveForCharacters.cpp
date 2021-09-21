#include<bits/stdc++.h>
using namespace std;

void solve(string s, int length){
    
    map<char, int> freq;
    for(int i=0;i<length;i++){
        char currentchar = s[i];
		freq[currentchar]++;
    }
    
	auto a_itr = freq.find('a');
    if(a_itr == freq.end())
        cout<<"0 ";
    else
        cout<<a_itr->second<<" ";
    
    auto s_itr = freq.find('s');
    if(s_itr == freq.end())
        cout<<"0 ";
    else
        cout<<s_itr->second<<" ";
    
    auto p_itr = freq.find('p');
    if(p_itr == freq.end())
        cout<<"0 ";
    else
        cout<<p_itr->second<<" ";
    
}

int main()
{
    int n;
    string str;
    cin>>n>>str;
    solve(str,n);
	return 0;
}