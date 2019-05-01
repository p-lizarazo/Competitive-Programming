
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> in(n);
	for(int i=0;i<n;++i){
		cin >> in[i];
	}
	sort(in.begin(),in.end());
	int acum=0;
	for(int i=0;i<n;i+=2){
		acum+=in[i+1]-in[i];
	}
	cout << acum;
	
	return 0;
}
