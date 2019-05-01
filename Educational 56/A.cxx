#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin >> t;
	
	int n;
	for(int i=0;i<t;i++){
		cin >> n;
		if(n%7!=0)
			cout << (n/7)+1 << "\n";
		else
			cout << n/7 << "\n";
	}
	return 0;
}
