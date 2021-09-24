#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll n,ll k){

	ll sum = 0;
	ll curr = n;

	while(curr>0){
		sum = sum + min(curr,k);
		curr = curr - k;
		curr = curr - (curr/10);
	}

	if( ( 2 * sum ) >= n )
		return true;
	else
		return false;

}


int main(){

	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;

		ll start = 1;
		ll end = n;

		ll ans = -1;

		while(start<=end){
			ll mid = ( start + end )/2;

			if(check(n, mid)){
				ans = mid;
				end = mid - 1;
			}
			else{
				start = mid + 1;
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}