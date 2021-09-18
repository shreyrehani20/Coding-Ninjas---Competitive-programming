#include<bits/stdc++.h>
using namespace std;

int minCostIterative(int ** input, int m, int n){

	int ** dp = new int * [m];
	for(int i=0;i<m;i++)
		dp[i] = new int [n];

	dp[m-1][n-1] = input[m-1][n-1];

	for(int i=m-2;i>=0;i--){
		dp[i][n-1] = dp[i+1][n-1] + input[i][n-1];
	}

	for(int j = n-2;j>=0;j--){
		dp[m-1][j] = dp[m-1][j+1] + input[m-1][j];
	}

	for(int i=m-2;i>=0;i--){
		for(int j=n-2;j>=0;j--){
			dp[i][j] = input[i][j] + min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j+1]));


		}
	}

	return dp[0][0];
}


int minCost(int ** input, int si, int sj, int ei, int ej, int ** dpOutput){

	if(si == ei && sj == ej){
		return input[ei][ej];
	}
	if(si > ei || sj > ej)
		return INT_MAX;

	if(dpOutput[si][sj] > -1)
		return dpOutput[si][sj];

	int option1 = minCost(input, si+1, sj, ei, ej, dpOutput);
	int option2 = minCost(input, si+1, sj+1, ei, ej, dpOutput);
	int option3 = minCost(input, si, sj+1, ei, ej, dpOutput);

	dpOutput[si][sj] = input[si][sj] + min(option1, min(option3, option2));

	return input[si][sj] + min(option1, min(option3, option2));

}




int main(){
	#ifndef ONLINE_JUDGE
		freopen("inputdp.txt","r",stdin);
		freopen("outputdp.txt","w",stdout);
	#endif

	int ** input = new int*[3];
	input[0] = new int[3];
	input[1] = new int[3];
	input[2] = new int[3];
	input[0][0] = 4;
	input[0][1] = 3;
	input[0][2] = 2;
	input[1][0] = 1;
	input[1][1] = 8;
	input[1][2] = 3;
	input[2][0] = 1;
	input[2][1] = 1;
	input[2][2] = 8;

	int ** dpOutput = new int*[4];
        for(int i=0;i<4;i++){
       		dpOutput[i] = new int[4];
        }
        for(int i=0;i<4;i++){
            for(int j = 0;j<4;j++){
                dpOutput[i][j] = -1;
            }
        }

	cout<<minCost(input, 0 ,0 ,2, 2, dpOutput)<<endl;
	
	cout<<minCostIterative(input, 3, 3);
	delete[] input[0];
	delete[] input[1];
	delete[] input[2];
	return 0;
}