#include <bits/stdc++.h>
using namespace std;

int pairSum(int *input, int n) {
    // Write your code here
    unordered_map<int, int> freq;
    unordered_map<int,int>::iterator it;
    int count = 0;
    for(int i=0;i<n;i++){
        
        it = freq.find(0-input[i]);
        if(it != freq.end()){
            count=count + it->second;
            freq[input[i]]++;
        }
        else{
            freq[input[i]]++;
        }
        
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}