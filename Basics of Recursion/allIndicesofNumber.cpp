#include<iostream>
#include "Solution.h"
using namespace std;


int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    if(size == 0)
        return ;
    
    int ans = allIndexes(input+1,size-1,x,output);
    
    for(int i=0;i<ans;i++)
        output[i] += 1;
    if(input[0] == x){
        for(int i=0;i<ans;i++){
            output[i+1] = output[i];
        }
        output[0] = 0;
        return ans + 1;
    }
    return ans;
    
    
}
// int allIndexes(int input[], int size, int x, int output[])
// {
//     if(size==0)
//     {
//         return 0;
//     }
//     int size_of_output=allIndexes(input+1, size-1, x, output);
//     for(int i=0; i<size_of_output; i++)
//     {
//         output[i]+=1;
//     }
//     if(input[0]==x&&size_of_output!=0)
//     {
//         for(int i=size_of_output-1; i>=0; i--)
//         {
//             output[i+1]=output[i];//shifting
//         }
//         output[0]=0;
//         return size_of_output+1;
//     }
//     else if(input[0]==x&&size_of_output==0)
//     {
//         output[0]=0;
//         return 1;
//     }
//     else if(input[0]!=x&&size_of_output==0)
//     {
//         return 0;
//     }
//     else if(input[0]!=x&&size_of_output!=0)
//     {
//         return size_of_output;
//     }
    
// }

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}