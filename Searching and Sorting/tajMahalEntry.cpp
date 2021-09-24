#include <iostream>
#include <climits>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long int *arr = new long long int [n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i] -= i - 1;
		if (arr[i] < 0)
			arr[i] = 0;

		long long int temp = arr[i] / n;
		
		if (arr[i] % n != 0)
			temp += 1;
		arr[i] = (n * temp) + i;
	}
	long long int finalAnswer = INT_MAX, rv = -1;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] < finalAnswer)
		{
			finalAnswer = arr[i];
			rv = i;
		}
	}
	cout << rv << endl;
}