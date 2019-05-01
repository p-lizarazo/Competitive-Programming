#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<ll> in(n/2);
	for(int i=0;i<n/2;++i){
		cin >> in[i];
	}
	
	vector<ll> out(n);
	
	out[0]=0;
	out[n-1]=in[0];
	for(int i=1;i<n/2;++i){
		if(out[n-i] <= in[i] && out[i-1]==0){
			out[n-1-i]= out[n-i];
			out[i]= in[i]-out[n-1-i];
		}
		else if(out[n-i] <= in[i] && out[i-1]!=0){
			if(in[i]-out[n-i] < out[i-1]){
				out[i]=out[i-1];
				out[n-1-i]=in[i]-out[i];
			} else {
				out[n-1-i]= out[n-i];
				out[i]= in[i]-out[n-1-i];
			}
		}
		else if(in[i] < out[n-i]){
			out[i]=out[i-1];
			out[n-1-i]=in[i]-out[i];
		}
	}
	
	for(int i=0;i<n;++i){
		cout << out[i] << " ";
	}
	
	return 0;
}
