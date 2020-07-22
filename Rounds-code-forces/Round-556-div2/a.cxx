#include<bits/stdc++.h>

using namespace std;

int main(){

		cin.tie(0);ios::sync_with_stdio(false);
	
	int n, m, r;
	cin >> n >> m >> r;
	
	int mini=1e9;
	for(int i=0;i<n;++i){
		int val; cin >> val;
		mini = min(mini, val);
	}
	
	int maxi=0;
	for(int i=0;i<m;++i){
		int val; cin >> val;
		maxi = max(maxi, val);
	}
	

	if(( r/mini*maxi + r%(mini) ) > r){
		cout << r/mini*maxi + r%(mini) << endl;
	} else{
		cout << r << endl;
	}


	return 0;
}
