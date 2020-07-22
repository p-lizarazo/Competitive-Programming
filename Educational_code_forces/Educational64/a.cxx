#include<bits/stdc++.h>

using ll = long long;
using namespace std;


int main(){
	//cin.tie(0);ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int cont=0;
	bool inf = false;
	int first;
	cin >> first;
	vector< int > values(n);
	values[0] = first;
	
	for(int i=1;i<n;++i){
		int val;
		cin >> val;
		values[i] = val;
		if(val == 1){
			if(first==2){
				cont+=3;
			} else if(first==3){
				cont+=4;
			} else{
				assert(false);
			}
		} else if(val == 2){
			if(first==1){
				cont+=3;
			} else if(first==3){
				inf = true;
			} else{
				assert(false);
			}
		} else if(val==3){
			
			if(first==1){
				cont+=4;
			} else if(first==2){
				inf = true;
			} else{
				assert(false);
			}
		} else{
			assert(false);
		}
		first = val;
	}
	
	
	for(int i=0;i+2<n;++i){
		if(values[i] == 3 && values[i+1] == 1 && values[i+2] == 2)
			cont--;
	}
	
	if(inf){
		cout << "Infinite";
	} else{
		cout << "Finite\n" << cont;
	}
	
	cout << "\n";

	return 0;
}
