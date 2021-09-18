#include<bits/stdc++.h>
using namespace std;
#define ll long long

int num_codes2(int* n, int size, int* arr) {
    
    int m = pow(10,9) + 7;
    
     if (size == 1) {
         return 1;
     }
     if (size == 0) {
         return 1;
     }
     if (arr[size] > 0) {
         return arr[size];
     }

     int output = num_codes2(n, size - 1, arr)%m;

     if (arr[size - 2] * 10 + arr[size - 1] <= 26) {
         output += num_codes2(n, size -2, arr)%m;
     }
     arr[size] = output;
     return output;
}


int main() {
    
    int t;
    cin>>t;
    while(t--){
        
        string s;
        cin>>s;
        int *arr = new int[s.size()+1];
        int *num = new int[s.size()];
        for( int i=0;i<s.size();i++){
            num[i] = s[i] - '0';
        }
        
        cout<<num_codes2(num, s.size(), arr);
        
    }
    return 0;

}