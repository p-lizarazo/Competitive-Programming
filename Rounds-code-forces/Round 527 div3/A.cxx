
#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,n,k;
	cin >> t;
	string s;
	char *ps;
	for(int i=0;i<t;++i){
		cin >> n >> k;
		ps = new char[n+1];
		for(int j=0;j<n;j++){
			ps[j]=('a')+(j%k);
		}
		ps[n]='\0';
		cout << ps << "\n"; 
	}
	return 0;
}
