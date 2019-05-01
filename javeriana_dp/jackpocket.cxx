#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
	int n;
	while(cin >> n && n!=0){
		ll seq = 0;
		ll maxi = 0;
		vector<ll> sum(n+1);
		sum[0]=0;
		for(int i=0;i<n;++i){
			int k;
			cin >> k;
			sum[i+1]=(seq+=k);
		}
		for(int i=0;i<n+1;++i){
			for(int j=i+1;j<n+1;j++){
				maxi = max(maxi, sum[j]-sum[i]);
			}
		}
		
		if(maxi>0){
			cout << "The maximum winning streak is " << maxi <<".\n";
		} else{
			cout << "Losing streak.\n";
		}
	}
	
	
	
	return 0;
}
