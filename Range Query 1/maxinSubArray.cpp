#include<bits/stdc++.h>
using namespace std;

void build(int *arr, int *tree, int start, int end, int treeNode){
    
    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }
    
    
    int mid = (start+end)/2;
    build(arr, tree, start, mid, 2*treeNode);
    build(arr, tree, mid + 1, end, 2*treeNode + 1);
    
    tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode + 1]);
    
}

void update(int *arr, int *tree, int start, int end, int treeNode, int idx, int val){
    
    if(start == end){
        arr[idx] = val;
        tree[treeNode] = val;
    	return;
    }
    
    
    int mid = (start + end)/2;
    if(idx > mid){
        update(arr, tree, mid + 1, end, 2*treeNode + 1, idx, val);
    }
    else{
        update(arr, tree, start, mid, 2*treeNode, idx, val);
    }
    
    tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode + 1]);
}

int query(int *tree, int start, int end, int treeNode, int left, int right ){
    
    
    if(start > right || end < left)
        return INT_MAX;
    
    if(start >= left && end <= right){
        return tree[treeNode];
    }
    
    int mid = (start + end)/2;
    int ans1 = query(tree, start, mid, 2*treeNode, left, right);
    int ans2 = query(tree, mid + 1, end, 2*treeNode + 1, left, right);
    
    return min(ans1, ans2);
}



int main(){
    
    // write your code here
    
    
    int n, q;
    cin>>n>>q;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int *tree = new int[4*n];
    
    build(arr, tree, 0, n-1, 1);
    
    char choice;
    int num1, num2;
    for(int i=0;i<q;i++){
        cin>>choice>>num1>>num2;
        if(choice == 'q'){
            int ans = query(tree, 0, n-1, 1, num1-1, num2-1);
            cout<<ans<<endl;
        }
        if(choice == 'u'){
            update(arr, tree, 0, n-1, 1, num1-1, num2);
        }
    }
    
    return 0;
}