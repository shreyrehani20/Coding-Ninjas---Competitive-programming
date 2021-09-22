#include <iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{
    //Write your code here
    unordered_map<int, int> duplicate;
    for(int i=0;i<n;i++){
        duplicate[arr[i]]++;
    }
    
    unordered_map<int, int>::iterator it;
    for(it = duplicate.begin(); it!=duplicate.end();it++){
        if(it->second == 2)
            return it->first;
    	
        else
            continue;
    }
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}