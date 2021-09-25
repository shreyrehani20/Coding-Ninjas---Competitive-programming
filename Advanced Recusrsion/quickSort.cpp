#include<bits/stdc++.h>
using namespace std;

int partition(int *a, int si, int ei){
	int pivot = a[si];
	int countSmaller = 0;
	for(int i=si+1;i<=ei;i++){
		if(a[i]<=pivot){
			countSmaller++;
		}
	}
	int pivotIndex = countSmaller + si;
	a[si] = a[pivotIndex];
	a[pivotIndex] = pivot;

	int i=si;
	int j=ei;
	while(i<pivotIndex && j>pivotIndex){
		if(a[i] <= pivot)
			i++;
		else if(a[j]>pivot)
			j--;
		else{
			int temp =a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	return pivotIndex;
}

void quickSort(int *arr, int si, int ei){
	if(si>=ei){
		return;
	}

	int p = partition(arr, si, ei);
	quickSort(arr, si, p-1);
	quickSort(arr, p+1, ei);
}



int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int *arr = new int[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		quickSort(arr, 0, n-1);
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}


	return 0;
}